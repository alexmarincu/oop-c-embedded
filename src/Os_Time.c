#include "Os_Time.h"
#include "TimeSource.h"
#include <time.h>

struct Os_Time {
    TimeSource timeSource;
};

Os_Time * Os_Time_getInstance(void) {
    static Os_Time self;
    return &self;
}

Os_Time * Os_Time_init(Os_Time * const self) {
    TimeSource_init((TimeSource *)self, (TimeSource_getCurrentTimeIn1msFun)Os_Time_getCurrentTimeIn1ms);
    return self;
}

uint32_t Os_Time_getCurrentTimeIn1ms(Os_Time * const self) {
    (void)self;
    return (uint32_t)(clock() / (CLOCKS_PER_SEC / 1000));
}
