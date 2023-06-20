#include "../../utils/src/time_source/TimeSource.h"
#include "SysTime.h"

uint32_t TimeSource_getCurrentOpTimeIn1ms(void) {
    return SysTime_getCurrentOpTimeIn1ms();
}
