#ifndef TimerClass_h
#define TimerClass_h
#include "TimeSource.h"

typedef struct {
    TimeSource * timeSource;
} TimerClass;

TimerClass * TimerClass_getInstance(void);
TimerClass * TimerClass_init(TimerClass * const self, TimeSource * const timeSource);

#endif // TimerClass_h
