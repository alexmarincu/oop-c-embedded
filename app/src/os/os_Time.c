#include "os_Time.h"
#include <time.h>

uint32_t os_Time_getCurrentTimeIn1ms(void) {
    return (uint32_t)(clock() / (CLOCKS_PER_SEC / 1000));
}
