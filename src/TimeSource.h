#ifndef TimeSource_h
#define TimeSource_h
#include <stdint.h>

typedef struct TimeSource TimeSource;
typedef uint32_t (*TimeSource_getCurrentTimeIn1msFun)(TimeSource const * const self);
struct TimeSource {
    TimeSource_getCurrentTimeIn1msFun getCurrentTimeIn1ms;
};

TimeSource * TimeSource_init(
    TimeSource * const self, TimeSource_getCurrentTimeIn1msFun getCurrentTimeIn1ms
);
uint32_t TimeSource_getCurrentTimeIn1ms(TimeSource const * const self);

#endif // TimeSource_h
