#include "Timer.h"

struct TimerClass {
    TimeSource * timeSource;
};

TimerClass * TimerClass_getInstance(void) {
    static TimerClass self;
    return &self;
}

TimerClass * TimerClass_init(TimerClass * const self, TimeSource * const timeSource) {
    self->timeSource = timeSource;
    return self;
}

Timer * Timer_init(Timer * const self) {
    self->klass = TimerClass_getInstance();
    self->startTimeIn1ms = 0;
    self->durationIn1ms = 0;
    self->isRunning = false;
    return self;
}

void Timer_start(Timer * const self, uint32_t const durationIn1ms) {
    self->startTimeIn1ms = TimeSource_getCurrentTimeIn1ms(self->klass->timeSource);
    self->durationIn1ms = durationIn1ms;
    self->isRunning = true;
}

bool Timer_isExpired(Timer const * const self) {
    return (
        (self->isRunning == true) &&
        ((TimeSource_getCurrentTimeIn1ms(self->klass->timeSource) - self->startTimeIn1ms) >= self->durationIn1ms)
    );
}