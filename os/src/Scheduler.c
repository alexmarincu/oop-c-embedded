#include "Scheduler.h"
#include "SysTime.h"

typedef struct Scheduler Scheduler;
struct Scheduler {
    Task * tasks;
    uint8_t count;
};

static Scheduler self;

void Scheduler_init(Task * const tasks, uint8_t const count) {
    self.tasks = tasks;
    self.count = count;
}

void Scheduler_run(void) {
    for (uint8_t i = 0; i < self.count; i++) {
        Task * task = &self.tasks[i];
        if (Task_shouldRun(task)) {
            Task_run(task);
        }
    }
}
