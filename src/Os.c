#include "Os.h"
#include "AccConfig.h"
#include "AccCtrl.h"
#include "AccDriverSwitch.h"
#include "Os_KeyHandler.h"
#include "Os_Scheduler.h"
#include "Os_Time.h"
#include "RealAccDriver.h"
#include "SimAccDriver.h"
#include "TimeSource.h"
#include "TimerClass.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

struct Os {
    Os_KeyHandler * osKeyHandler;
    Os_Scheduler * osScheduler;
    bool shouldQuit;
    uint32_t last100msLoopOpTimeIn1ms;
};

Os * Os_getInstance(void) {
    static Os self;
    return &self;
}

Os * Os_init(Os * const self) {
    self->osKeyHandler = Os_KeyHandler_init(Os_KeyHandler_getInstance());
    self->osScheduler = Os_Scheduler_init(Os_Scheduler_getInstance());
    AccConfig_init(AccConfig_getInstance());
    SimAccDriver_init(SimAccDriver_getInstance());
    AccCtrl_init(AccCtrl_getInstance(), (AccDriver *)RealAccDriver_init(RealAccDriver_getInstance()));
    AccDriverSwitch_init(AccDriverSwitch_getInstance());
    TimerClass_init(TimerClass_getInstance(), (TimeSource *)Os_Time_getInstance());
    self->shouldQuit = false;
    return self;
}

void Os_run(Os * const self) {
    printf("Press 'q' to quit.\n");
    while (!self->shouldQuit) {
        Os_KeyHandler_run(self->osKeyHandler);
        Os_Scheduler_run(self->osScheduler);
    }
    printf("Quitting...\n");
}

void Os_quit(Os * const self) {
    self->shouldQuit = true;
}