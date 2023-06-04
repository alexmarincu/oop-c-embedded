#include "TimeSource.h"

TimeSource * TimeSource_init(
    TimeSource * const self, TimeSource_getCurrentTimeIn1msFun getCurrentTimeIn1ms
) {
    self->getCurrentTimeIn1ms = getCurrentTimeIn1ms;
    return self;
}

uint32_t TimeSource_getCurrentTimeIn1ms(TimeSource const * const self) {
    return self->getCurrentTimeIn1ms(self);
}