#include "SysTime.h"
#include <time.h>

uint32_t SysTime_getOpTimeIn1ms(void) {
    return (uint32_t)(clock() / (CLOCKS_PER_SEC / 1000));
}
