#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

//// Compatibility
#if defined POSIX
#define CLEARSCR system ( "clear" )
#elif defined MSDOS || defined WIN32
#define CLEARSCR system ( "cls" )
#endif

//// Application constants
#define TITLE "CARRETERAS"

// Errors
#define INSUFFICIENT_MEMORY "ERROR. Memoria insuficiente."

//// Prototypes
void show_menu(void);
char get_option(void);
void execute(void);

#endif // COMMON_H_INCLUDED
