#include "Os.h"
#include "os_KeyHandler.h"
#include "os_Scheduler.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

struct Os {
    os_KeyHandler * osKeyHandler;
    os_Scheduler * osScheduler;
    bool shouldQuit;
    uint32_t last100msLoopOpTimeIn1ms;
};

Os * Os_getInstance(void) {
    static Os self;
    return &self;
}

Os * Os_init(Os * const self) {
    self->osKeyHandler = os_KeyHandler_init(os_KeyHandler_getInstance());
    self->osScheduler = os_Scheduler_init(os_Scheduler_getInstance());
    self->shouldQuit = false;
    return self;
}

void Os_run(Os * const self) {
    printf("Press 'q' to quit.\n");
    while (!self->shouldQuit) {
        os_KeyHandler_run(self->osKeyHandler);
        os_Scheduler_run(self->osScheduler);
    }
    printf("Quitting...\n");
}

void Os_quit(Os * const self) {
    self->shouldQuit = true;
}