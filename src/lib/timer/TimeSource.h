#ifndef TimeSource_h
#define TimeSource_h
#include <stdint.h>

typedef struct TimeSource TimeSource;
typedef uint32_t (*TimeSource_getCurrentTimeIn1msFun)(TimeSource const * const self);
struct TimeSource {
    void * impl;
    TimeSource_getCurrentTimeIn1msFun getCurrentTimeIn1ms;
};

TimeSource * TimeSource_init(
    TimeSource * const self, void * const impl, TimeSource_getCurrentTimeIn1msFun getCurrentTimeIn1ms
);
uint32_t TimeSource_getCurrentTimeIn1ms(TimeSource const * const self);

#endif // TimeSource_h
