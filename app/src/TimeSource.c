#include "../../utils/src/time_source/TimeSource.h"
#include "../../os/src/SysTime.h"

uint32_t TimeSource_getOpTimeIn1ms(void) {
    return SysTime_getOpTimeIn1ms();
}
