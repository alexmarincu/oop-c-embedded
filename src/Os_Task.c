#include "Os_Task.h"
#include <stdbool.h>

struct Os_TaskClass {
    Os_Time * osTime;
};

Os_TaskClass * Os_TaskClass_getInstance(void) {
    static Os_TaskClass self;
    return &self;
}

Os_TaskClass * Os_TaskClass_init(Os_TaskClass * const self) {
    self->osTime = Os_Time_getInstance();
    return self;
}

Os_Task * Os_Task_init(
    Os_Task * const self,
    uint32_t const repetitionRateIn1ms, void * const client, Os_Task_operationFun const operation
) {
    self->klass = Os_TaskClass_getInstance();
    self->startTimeAtLastRunIn1ms = UINT32_MAX;
    self->maxRunDurationIn1ms = 0;
    self->repetitionRateIn1ms = repetitionRateIn1ms;
    self->client = client;
    self->operation = operation;
    return self;
}

static bool Os_Task_shouldRun(Os_Task * const self) {
    uint32_t const currentTimeIntervalIn1ms = Os_Time_getCurrentTimeIn1ms(self->klass->osTime) - self->startTimeAtLastRunIn1ms;
    return (currentTimeIntervalIn1ms >= self->repetitionRateIn1ms);
}

void Os_Task_run(Os_Task * const self) {
    if (Os_Task_shouldRun(self)) {
        self->startTimeAtLastRunIn1ms = Os_Time_getCurrentTimeIn1ms(self->klass->osTime);
        self->operation(self->client);
        uint32_t runDurationIn1ms = Os_Time_getCurrentTimeIn1ms(self->klass->osTime) - self->startTimeAtLastRunIn1ms;
        if (runDurationIn1ms > self->maxRunDurationIn1ms) {
            self->maxRunDurationIn1ms = runDurationIn1ms;
        }
    }
}
