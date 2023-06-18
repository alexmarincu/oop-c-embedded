#include "../../../utils/src/time_source/TimeSource.h"
#include "os_Time.h"

uint32_t TimeSource_getCurrentTimeIn1ms(void) {
    return os_Time_getCurrentTimeIn1ms();
}
