#include "Os_Scheduler.h"
#include "AccCtrl.h"
#include "Os_Task.h"

struct Os_Scheduler {
    AccCtrl * accCtrl;
    Os_Task tasks[4];
};

Os_Scheduler * Os_Scheduler_getInstance(void) {
    static Os_Scheduler self;
    return &self;
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

Os_Scheduler * Os_Scheduler_init(Os_Scheduler * const self) {
    self->accCtrl = AccCtrl_getInstance();
    Os_Task_init(&self->tasks[0], 10, self, (Os_Task_operationFun)Os_Scheduler_runAt10ms);
    Os_Task_init(&self->tasks[1], 20, self, (Os_Task_operationFun)Os_Scheduler_runAt20ms);
    Os_Task_init(&self->tasks[2], 50, self, (Os_Task_operationFun)Os_Scheduler_runAt50ms);
    Os_Task_init(&self->tasks[3], 100, self, (Os_Task_operationFun)Os_Scheduler_runAt100ms);
    return self;
}

void Os_Scheduler_run(Os_Scheduler * const self) {
    for (uint8_t i = 0; i < 4; i++) {
        Os_Task_run(&self->tasks[i]);
    }
}
