#ifndef TimerClass_h
#define TimerClass_h
#include "TimeSource.h"

typedef struct {
    TimeSource * timeSource;
} TimerClass;

TimerClass * TimerClass_init(TimerClass * const self, TimeSource * const timeSource);
TimerClass * TimerClass_getInstance(void);

#endif // TimerClass_h
