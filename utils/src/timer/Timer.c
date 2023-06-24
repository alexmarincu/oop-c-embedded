#include "Timer.h"
#include "TimeSource.h"

Timer * Timer_init(Timer * const self, uint32_t const durationIn1ms) {
    self->startTimeIn1ms = 0;
    self->durationIn1ms = durationIn1ms;
    self->isRunning = false;
    return self;
}

void Timer_start(Timer * const self) {
    self->startTimeIn1ms = TimeSource_getOpTimeIn1ms();
    self->isRunning = true;
}

void Timer_stop(Timer * const self) {
    Timer_init(self, self->durationIn1ms);
}

bool Timer_isRunning(Timer * const self) {
    return self->isRunning;
}

bool Timer_isExpired(Timer * const self) {
    return (
        (self->isRunning == true) &&
        ((TimeSource_getOpTimeIn1ms() - self->startTimeIn1ms) >= self->durationIn1ms)
    );
}