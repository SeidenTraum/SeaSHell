#ifndef _GLBOAL_H_
#define _GLBOAL_H_

// Buffer sizes
// 2**i (starts at 4, step of 2)
#define sBufferSS   16      // Extra small buffer       (16   Bytes)
#define sBufferS    64      // Small buffer             (64   Bytes)
#define sBufferA    256     // Medium buffer            (256  Bytes)
#define sBufferL    1024    // Large buffer             (1    Kilobyte)
#define sBufferXL   4096    // Extra large buffer       (4    Kilobytes)
#define sBufferXXL  16384   // Extra extra large buffer (16   Kilobytes)
// OVERKILL
#define sBufferT    1048576 // Titanic buffer [2**20]   (1 Megabyte)

// Escape codes
#define CTRL_D 4
#define CTRL_C 3
#define CTRL_L 12
#define BSPACE 127 // Some systems use 127
#define bBSPACE 8  // Some use 8 
#define TAB     9

// Keyboard arrows
#define UPARR 'A'
#define DWARR 'B'
#define RIARR 'C'
#define LEARR 'D'

#endif // !_GLBOAL_H_
