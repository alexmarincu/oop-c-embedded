#include "Timer.h"
#include "TimeSource.h"

Timer * Timer_init(Timer * const self) {
    self->klass = TimerClass_getInstance();
    self->startTimeInMs = 0;
    self->durationInMs = 0;
    self->isRunning = false;
    return self;
}

void Timer_start(Timer * const self, uint32_t const durationInMs) {
    self->startTimeInMs = TimeSource_getCurrentTimeInMs(self->klass->timeSource);
    self->durationInMs = durationInMs;
    self->isRunning = true;
}

bool Timer_isExpired(Timer const * const self) {
    return (
        (self->isRunning == true) &&
        ((TimeSource_getCurrentTimeInMs(self->klass->timeSource) - self->startTimeInMs) >= self->durationInMs)
    );
}