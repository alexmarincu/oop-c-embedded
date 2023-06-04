#include "SimOs.h"
#include "AccelConfig.h"
#include "AccelCtrl.h"
#include "AccelDriverSwitch.h"
#include "RealAccelDriver.h"
#include "SimAccelDriver.h"
#include "TimeSource.h"
#include "TimerClass.h"
#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

struct SimOs {
    TimeSource timeSource;
    AccelConfig * accelConfig;
    AccelCtrl * accelCtrl;
    AccelDriverSwitch * accelDriverSwitch;
    RealAccelDriver * realAccelDriver;
    SimAccelDriver * simAccelDriver;
    TimerClass * timerClass;
    bool shouldQuit;
    uint32_t last100msLoopOpTimeInMs;
};

static uint32_t SimOs_getCurrentTimeInMs(SimOs * const self);

SimOs * SimOs_getInstance(void) {
    static SimOs self;
    return &self;
}

SimOs * SimOs_init(SimOs * const self) {
    TimeSource_init((TimeSource *)self, (TimeSource_getCurrentTimeInMsFun)SimOs_getCurrentTimeInMs);
    self->accelConfig = AccelConfig_getInstance();
    self->accelCtrl = AccelCtrl_getInstance();
    self->accelDriverSwitch = AccelDriverSwitch_getInstance();
    self->realAccelDriver = RealAccelDriver_getInstance();
    self->simAccelDriver = SimAccelDriver_getInstance();
    self->timerClass = TimerClass_getInstance();
    AccelConfig_init(self->accelConfig);
    RealAccelDriver_init(self->realAccelDriver);
    SimAccelDriver_init(self->simAccelDriver);
    AccelCtrl_init(self->accelCtrl, (AccelDriver *)self->realAccelDriver);
    AccelDriverSwitch_init(self->accelDriverSwitch);
    TimerClass_init(self->timerClass, (TimeSource *)self);
    self->shouldQuit = false;
    self->last100msLoopOpTimeInMs = UINT32_MAX;
    return self;
}

static void SimOs_rKeyInt(SimOs * const self) {
    AccelDriver_dataAvailableInt((AccelDriver *)self->realAccelDriver);
}

static void SimOs_sKeyInt(SimOs * const self) {
    AccelDriver_dataAvailableInt((AccelDriver *)self->simAccelDriver);
}

static void SimOs_tKeyInt(SimOs * const self) {
    AccelConfig_toggleAccelDriver(self->accelConfig);
}

static void SimOs_qKeyInt(SimOs * const self) {
    self->shouldQuit = true;
}

static void SimOs_100msLoop(SimOs * const self) {
    AccelCtrl_main(self->accelCtrl);
}

static void SimOs_keyIntHandler(SimOs * const self) {
    if (_kbhit()) {
        int key = _getch();
        switch (key) {
            case 'r': {
                SimOs_rKeyInt(self);
            } break;
            case 's': {
                SimOs_sKeyInt(self);
            } break;
            case 't': {
                SimOs_tKeyInt(self);
            } break;
            case 'q': {
                SimOs_qKeyInt(self);
            } break;
            default: {
            } break;
        }
    }
}

static uint32_t SimOs_getCurrentTimeInMs(SimOs * const self) {
    (void)self;
    return (uint32_t)(clock() / (CLOCKS_PER_SEC / 1000));
}

static void SimOs_loopHandler(SimOs * const self) {
    uint32_t const currentOpTimeInMs = SimOs_getCurrentTimeInMs(self);
    if (currentOpTimeInMs - self->last100msLoopOpTimeInMs >= 100) {
        self->last100msLoopOpTimeInMs = currentOpTimeInMs;
        SimOs_100msLoop(self);
    }
}

void SimOs_main(SimOs * const self) {
    printf("Press 'q' to quit.\n");
    while (!self->shouldQuit) {
        SimOs_keyIntHandler(self);
        SimOs_loopHandler(self);
    }
    printf("Quitting...\n");
}
