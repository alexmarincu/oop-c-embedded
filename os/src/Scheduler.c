#include "Scheduler.h"
#include "SysTime.h"
#include <stddef.h>

typedef struct Scheduler Scheduler;
struct Scheduler {
    Task * tasks;
    uint8_t count;
};

static Scheduler self = {
    .tasks = NULL,
    .count = 0
};

void Scheduler_setTasks(Task * const tasks, uint8_t const count) {
    self.tasks = tasks;
    self.count = count;
}

void Scheduler_main(void) {
    for (uint8_t i = 0; i < self.count; i++) {
        Task_main(&self.tasks[i]);
    }
}
