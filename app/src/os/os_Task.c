#include "os_Task.h"
#include "os_Time.h"
#include <stdbool.h>

os_Task * os_Task_init(
    os_Task * const self,
    uint32_t const repetitionRateIn1ms, void * const client, os_Task_operationFun const operation
) {
    self->startTimeAtLastRunIn1ms = 0;
    self->maxRunDurationIn1ms = 0;
    self->repetitionRateIn1ms = repetitionRateIn1ms;
    self->client = client;
    self->operation = operation;
    return self;
}

static bool os_Task_shouldRun(os_Task * const self) {
    uint32_t const currentTimeIntervalIn1ms = os_Time_getCurrentTimeIn1ms() - self->startTimeAtLastRunIn1ms;
    return (currentTimeIntervalIn1ms >= self->repetitionRateIn1ms);
}

void os_Task_run(os_Task * const self) {
    if (os_Task_shouldRun(self)) {
        self->startTimeAtLastRunIn1ms = os_Time_getCurrentTimeIn1ms();
        self->operation(self->client);
        uint32_t runDurationIn1ms = os_Time_getCurrentTimeIn1ms() - self->startTimeAtLastRunIn1ms;
        if (runDurationIn1ms > self->maxRunDurationIn1ms) {
            self->maxRunDurationIn1ms = runDurationIn1ms;
        }
    }
}