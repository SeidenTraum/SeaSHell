#include "../core.h"
#include "../../include/status.h"
#include <unistd.h>

int cd(char *dir) {
  if (chdir(dir) != 0) {
    return CHDIRERR;
  } else {
    /* Should update env vars */
    ;
  }

  return SUCCESS;
}
