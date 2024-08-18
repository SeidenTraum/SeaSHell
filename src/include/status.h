#ifndef _STATUS_H_
#define _STATUS_H_

// Success Code
#define SUCCESS          0  // Operation completed successfully

// Process Management Errors
#define FORKFAIL        -1  // Failure to fork a process
#define CHILDTERMFAIL   -2  // Failure to terminate a child process
#define EXECFAIL        -3  // Failure to execute a process

// Directory and File Errors
#define DIRNOTFOUND     -4  // Pointer to DIR stream is NULL
#define CHDIRERR        -5  // Failure to change directories

// General Errors
#define UNSPEC          -6  // Unspecified error
#define NULLPTR         -7  // Generic NULL pointer error

#endif // !_STATUS_H_
