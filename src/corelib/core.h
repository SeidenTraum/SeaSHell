#ifndef _CORE_H_
#define _CORE_H_

/* Forks proc and runs args on child */
int nproc(char **args);

/* Runs inbuilt proc*/
int iproc(char **args);

/* Disables echoing of characters 
 * and enables char-by-char processing */
void enableRawMode();

/* Sets the terminal to 
 * it's original canonical mode */
void disableRawMode();

/* Changes directory */
int cd(char *dir);

#endif // !_CORE_H_
