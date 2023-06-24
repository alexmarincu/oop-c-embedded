#ifndef coniow_h
#define coniow_h
#ifdef _WIN32
#include <conio.h>
#else
int _kbhit(void);
int _getch(void);
#endif
#endif // coniow_h
