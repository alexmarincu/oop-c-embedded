#ifndef TimeSource_h
#define TimeSource_h
#include <stdint.h>

typedef struct TimeSource TimeSource;
typedef uint32_t (*TimeSource_getCurrentTimeInMsFun)(TimeSource const * const self);
struct TimeSource {
    TimeSource_getCurrentTimeInMsFun getCurrentTimeInMs;
};

TimeSource * TimeSource_init(
    TimeSource * const self, TimeSource_getCurrentTimeInMsFun getCurrentTimeInMs
);
uint32_t TimeSource_getCurrentTimeInMs(TimeSource const * const self);

#endif // TimeSource_h
