#include "Os.h"
#include "Scheduler.h"
#include <stdbool.h>
#include <stdint.h>

void Os_run(void) {
    while (1) {
        Scheduler_run();
    }
}
