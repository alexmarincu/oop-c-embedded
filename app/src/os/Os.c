#include "Os.h"
#include "KeyHandler.h"
#include "Scheduler.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef struct Os Os;
struct Os {
    Scheduler * scheduler;
    bool shouldQuit;
    uint32_t last100msLoopOpTimeIn1ms;
};

static Os self;

void Os_init(void) {
    KeyHandler_init();
    self.scheduler = Scheduler_init(Scheduler_getInstance());
    self.shouldQuit = false;
}

void Os_run(void) {
    printf("Press 'q' to quit.\n");
    while (!self.shouldQuit) {
        KeyHandler_run();
        Scheduler_run(self.scheduler);
    }
    printf("Quitting...\n");
}

void Os_quit(void) {
    self.shouldQuit = true;
}