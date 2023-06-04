#include "TimerClass.h"

TimerClass * TimerClass_getInstance(void) {
    static TimerClass self;
    return &self;
}

TimerClass * TimerClass_init(TimerClass * const self, TimeSource * const timeSource) {
    self->timeSource = timeSource;
    return self;
}