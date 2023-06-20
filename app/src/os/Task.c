#include "Task.h"
#include "SysTime.h"
#include <stdbool.h>

Task * Task_init(
    Task * const self,
    uint32_t const repetitionRateIn1ms, void * const client, Task_operationFun const operation
) {
    self->startTimeAtLastRunIn1ms = 0;
    self->maxRunDurationIn1ms = 0;
    self->repetitionRateIn1ms = repetitionRateIn1ms;
    self->client = client;
    self->operation = operation;
    return self;
}

static bool Task_shouldRun(Task * const self) {
    uint32_t const currentTimeIntervalIn1ms = SysTime_getCurrentOpTimeIn1ms() - self->startTimeAtLastRunIn1ms;
    return (currentTimeIntervalIn1ms >= self->repetitionRateIn1ms);
}

void Task_run(Task * const self) {
    if (Task_shouldRun(self)) {
        self->startTimeAtLastRunIn1ms = SysTime_getCurrentOpTimeIn1ms();
        self->operation(self->client);
        uint32_t runDurationIn1ms = SysTime_getCurrentOpTimeIn1ms() - self->startTimeAtLastRunIn1ms;
        if (runDurationIn1ms > self->maxRunDurationIn1ms) {
            self->maxRunDurationIn1ms = runDurationIn1ms;
        }
    }
}
