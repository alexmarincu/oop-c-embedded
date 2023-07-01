#include "Os.h"
#include "Scheduler.h"
#include <stdbool.h>
#include <stdint.h>

void Os_main(void) {
    while (1) {
        Scheduler_main();
    }
}
