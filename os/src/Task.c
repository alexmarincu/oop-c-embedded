#include "Task.h"
#include "SysTime.h"
#include <stdbool.h>

Task * Task_init(Task * const self, uint32_t const repetitionRateIn1ms, Task_operationFun const operation) {
    self->startTimeAtLastRunIn1ms = 0;
    self->repetitionRateIn1ms = repetitionRateIn1ms;
    self->operation = operation;
    return self;
}

static bool Task_shouldRun(Task * const self) {
    uint32_t const elapsedTimeIn1ms = SysTime_getOpTimeIn1ms() - self->startTimeAtLastRunIn1ms;
    return (elapsedTimeIn1ms >= self->repetitionRateIn1ms);
}

void Task_main(Task * const self) {
    if (Task_shouldRun(self)) {
        self->startTimeAtLastRunIn1ms = SysTime_getOpTimeIn1ms();
        self->operation();
    }
}
