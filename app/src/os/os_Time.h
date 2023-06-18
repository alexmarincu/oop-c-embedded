#ifndef os_Time_h
#define os_Time_h
#include "../../../utils/src/timer/TimeSource.h"
#include <stdint.h>

typedef struct os_Time os_Time;

os_Time * os_Time_getInstance(void);
os_Time * os_Time_init(os_Time * const self);
TimeSource * os_Time_getTimeSource(os_Time * const self);
uint32_t os_Time_getCurrentTimeIn1ms(os_Time * const self);

#endif // os_Time_h
