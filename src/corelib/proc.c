#include "../include/status.h"
#include "core.h"
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

int nproc(char **args) {
  pid_t pid = fork();
  if (pid == -1) {
    // Fork failure
    return FORKFAIL;
  } else if (pid == 0) {
    // Creates child process
    if (execvp(args[0], args) == -1) {
      // Failure to execute
      return EXECFAIL;
    }
  } else {
    // Parent process
    int status;
    waitpid(pid, &status, 0); // Wait for child process to finish

    // Checking termination status of child
    if (WIFEXITED(status)) {
      return WEXITSTATUS(status); // Returns child's status
    } else {
      // Child could not be terminated
      return CHILDTERMFAIL;
    }
  }

  return SUCCESS;
}

int iproc(char **args) {
  if (strcmp(args[0], "cd") == 0) {
    cd(args[1]);
  }
  else {
    return EXECFAIL;
  }
  return SUCCESS;
}
