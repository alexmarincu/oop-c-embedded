#include "Timer.h"
#include "../time_source/TimeSource.h"

Timer * Timer_init(Timer * const self) {
    self->startTimeIn1ms = 0;
    self->durationIn1ms = 0;
    self->isRunning = false;
    return self;
}

void Timer_start(Timer * const self, uint32_t const durationIn1ms) {
    self->startTimeIn1ms = TimeSource_getCurrentTimeIn1ms();
    self->durationIn1ms = durationIn1ms;
    self->isRunning = true;
}

bool Timer_isExpired(Timer * const self) {
    return (
        (self->isRunning == true) &&
        ((TimeSource_getCurrentTimeIn1ms() - self->startTimeIn1ms) >= self->durationIn1ms)
    );
}