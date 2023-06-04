#ifndef Os_Time_h
#define Os_Time_h
#include <stdint.h>

typedef struct Os_Time Os_Time;

Os_Time * Os_Time_getInstance(void);
Os_Time * Os_Time_init(Os_Time * const self);
uint32_t Os_Time_getCurrentTimeIn1ms(Os_Time * const self);

#endif // Os_Time_h
