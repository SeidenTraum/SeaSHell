#include "core.h"
#include <termios.h>
#include <unistd.h>

void enableRawMode() {
  // Disables echoing of characters and enables char-by-char processing
  struct termios raw;
  tcgetattr(STDIN_FILENO, &raw);  // Retrieve current terminal attributes
  // STDIN_FILENO is the file descriptor for stdin (usually the keyboard)
  raw.c_lflag &= ~(ECHO | ICANON);  // Modifies terminal attributes
  // ECHO means input is not echoed (what user write doesn't appear in screen)
  // ICANON disables canonical (cooked) mode, enabling raw mode (char-by-char input)
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);  // Apply the modified attributes
  // TCSAFLUSH means that it should flush IO queues (Discards any unread input)
}

void disableRawMode() {
  // Sets the terminal back to it's original canonical (cooked) mode
  struct termios raw;
  tcgetattr(STDIN_FILENO, &raw); // Retrieves current terminal attributes
  raw.c_lflag |= (ECHO | ICANON); // Re-enable echoing and canonical mode
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw); // Apply the restored attributes
}

