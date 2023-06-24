#include "Os.h"
#include "Interrupts.h"
#include "KeyHandler.h"
#include "Scheduler.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef struct Os Os;
struct Os {
    bool shouldQuit;
};

static Os self;

void Os_init(Task * const tasks, uint8_t const count) {
    Scheduler_init(tasks, count);
    Interrupts_init();
    self.shouldQuit = false;
}

void Os_run(void) {
    printf("Press 'q' to quit.\n");
    while (!self.shouldQuit) {
        KeyHandler_run();
        Scheduler_run();
    }
    printf("Quitting...\n");
}

void Os_quit(void) {
    self.shouldQuit = true;
}