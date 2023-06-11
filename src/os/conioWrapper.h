#ifndef conioWrapper_h
#define conioWrapper_h
#ifdef _WIN32
#include <conio.h>
#else
int _kbhit(void);
int _getch(void);
#endif
#endif // conioWrapper_h
