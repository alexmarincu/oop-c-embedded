#include "TimeSource.h"

TimeSource * TimeSource_init(
    TimeSource * const self, TimeSource_getCurrentTimeInMsFun getCurrentTimeInMs
) {
    self->getCurrentTimeInMs = getCurrentTimeInMs;
    return self;
}

uint32_t TimeSource_getCurrentTimeInMs(TimeSource const * const self) {
    return self->getCurrentTimeInMs(self);
}