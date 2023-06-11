#include "os_Time.h"
#include <time.h>

struct os_Time {
    TimeSource timeSource;
};

os_Time * os_Time_getInstance(void) {
    static os_Time self;
    return &self;
}

os_Time * os_Time_init(os_Time * const self) {
    TimeSource_init((TimeSource *)self, self, (TimeSource_getCurrentTimeIn1msFun)os_Time_getCurrentTimeIn1ms);
    return self;
}

TimeSource * os_Time_getTimeSource(os_Time * const self) {
    return &self->timeSource;
}

uint32_t os_Time_getCurrentTimeIn1ms(os_Time * const self) {
    (void)self;
    return (uint32_t)(clock() / (CLOCKS_PER_SEC / 1000));
}
