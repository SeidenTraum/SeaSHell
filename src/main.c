#include "corelib/core.h"
#include "include/global.h"
#include "include/status.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>

void split(char *str, char *dest[]); 
void displayHandle() {
  uid_t uid = getuid();
  struct passwd *pw = getpwuid(uid);

  printf("\033[33;1m%s ~> \033[0m", pw->pw_name);
}

int main() {
  // Main variables
  bool dHandle = true;
  char *buffer;
  int sBuffer = sBufferS; // 64 characters
  char c;
  int idx = 0;
  int hidx = idx;

  buffer = malloc(sBuffer);
  if (buffer == NULL) {
    /* This would happen if
     * malloc failed to allocate
     * the resources*/
    return NULLPTR;
  }

  enableRawMode();
  while (true) {
    if (dHandle == true) {
      displayHandle();
      fflush(stdout);
      dHandle = false;
    }

    if (read(STDIN_FILENO, &c, 1) == 1) {
      // Checking inputs
      if (c == CTRL_D) {
        printf("Manual interruption\n");
        break;
      }
      else if ( c == CTRL_C) {
        printf("Manual interruption\n");
        break;
      }
      else if (c == CTRL_L) {
        dHandle = true;
        printf("\033c");
        hidx = idx = 0;
        continue;
      }
      else if (c == TAB) {
        continue;
      }
      else if (c == BSPACE || c == bBSPACE) {
        if (idx > 0) {
          idx--;
          printf("\b \b");
          fflush(stdout);
        }
        continue;
      }
      else if (c == '\033') {
        /* Start of an escape sequence
        * The code under is to disable the up and down keys
        * and limit the movement of the left and right keys
        * so they can't reach the handle */
        char seq[2];
        if (read(STDIN_FILENO, &seq[0], 1) == 0) continue;
        if (read(STDIN_FILENO, &seq[1], 1) == 0) continue;
        // Now seq contains two characters after \033
        // Ignore the sequence to prevent cursor movement
        if (seq[0] == '[' && (seq[1] == UPARR || seq[1] == DWARR)) {
          continue; // Do nothing for arrow keys
        }
        if (seq[0] == '[' && (seq[1] == LEARR)) {
          if (hidx > 0) {
            printf("\033[D");
            fflush(stdout);
            hidx--;
          }
        }
        if (seq[0] == '[' && (seq[1] == RIARR) && buffer[hidx] != '\0') {
          printf("\033[C");
          fflush(stdout);
          hidx++;
        }
        continue;
      }
      else if (c == '\n') {
        // This is the Return key
        char *stdbfr[sBufferS];
        putchar('\n');
        dHandle = true;
        buffer[idx] = '\0';
        split(buffer, stdbfr);
        if (strcmp(stdbfr[0], "exit") == 0) {
          printf("Manual interruption\n");
          exit(SUCCESS);
        }
        if (iproc(stdbfr) < 0){
          if (nproc(stdbfr) < 0) {
            printf("Womp womp\n");
            return UNSPEC;
          }
        }

        hidx = idx = 0;
      }
      else {
        if (idx >= sBuffer -1) {
          sBuffer = idx +1;
          buffer = realloc(buffer, sBuffer);
          if (buffer == NULL) {
            // Buffer couldn't allocate memory
            return NULLPTR;
          }
        }
        buffer[idx++] = c;
        putchar(c);
        hidx = idx;
        fflush(stdout);
      }
    }
  }

  disableRawMode();
}

void split(char *str, char *dest[]) {
  /* Breaks a string apart */
  char *token = strtok(str, " ");
  int i = 0;

  while (token != NULL) {
    dest[i++] = token;
    token = strtok(NULL, " ");
  }
  dest[i] = NULL;
}
