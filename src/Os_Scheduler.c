#include "Os_Scheduler.h"
#include "AccCtrl.h"
#include "Os_Time.h"

struct Os_Scheduler {
    AccCtrl * accCtrl;
    Os_Time * osTime;
    uint32_t timeAtLast10msRunIn1ms;
    uint32_t timeAtLast20msRunIn1ms;
    uint32_t timeAtLast50msRunIn1ms;
    uint32_t timeAtLast100msRunIn1ms;
};

Os_Scheduler * Os_Scheduler_getInstance(void) {
    static Os_Scheduler self;
    return &self;
}

Os_Scheduler * Os_Scheduler_init(Os_Scheduler * const self) {
    self->accCtrl = AccCtrl_getInstance();
    self->osTime = Os_Time_getInstance();
    self->timeAtLast10msRunIn1ms = UINT32_MAX;
    self->timeAtLast20msRunIn1ms = UINT32_MAX;
    self->timeAtLast50msRunIn1ms = UINT32_MAX;
    self->timeAtLast100msRunIn1ms = UINT32_MAX;
    return self;
}

static void Os_Scheduler_runAt10ms(Os_Scheduler * const self) {
    (void)self;
}

static void Os_Scheduler_runAt20ms(Os_Scheduler * const self) {
    (void)self;
}

static void Os_Scheduler_runAt50ms(Os_Scheduler * const self) {
    (void)self;
}

static void Os_Scheduler_runAt100ms(Os_Scheduler * const self) {
    AccCtrl_run(self->accCtrl);
}

void Os_Scheduler_run(Os_Scheduler * const self) {
    uint32_t const currentTimeIn1ms = Os_Time_getCurrentTimeIn1ms(self->osTime);
    if (currentTimeIn1ms - self->timeAtLast10msRunIn1ms >= 10) {
        self->timeAtLast10msRunIn1ms = currentTimeIn1ms;
        Os_Scheduler_runAt10ms(self);
    }
    if (currentTimeIn1ms - self->timeAtLast20msRunIn1ms >= 20) {
        self->timeAtLast20msRunIn1ms = currentTimeIn1ms;
        Os_Scheduler_runAt20ms(self);
    }
    if (currentTimeIn1ms - self->timeAtLast50msRunIn1ms >= 50) {
        self->timeAtLast50msRunIn1ms = currentTimeIn1ms;
        Os_Scheduler_runAt50ms(self);
    }
    if (currentTimeIn1ms - self->timeAtLast100msRunIn1ms >= 100) {
        self->timeAtLast100msRunIn1ms = currentTimeIn1ms;
        Os_Scheduler_runAt100ms(self);
    }
}
