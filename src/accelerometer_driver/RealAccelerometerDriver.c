#include "RealAccelerometerDriver.h"
#include "AccelerometerDriver.h"
#include <stdio.h>

struct RealAccelerometerDriver {
    AccelerometerDriver accelerometerDriver;
};

RealAccelerometerDriver * RealAccelerometerDriver_getInstance(void) {
    static RealAccelerometerDriver self;
    return &self;
}

RealAccelerometerDriver * RealAccelerometerDriver_init(
    RealAccelerometerDriver * const self, AccelerometerCtrl * const accelerometerCtrl
) {
    AccelerometerDriver_init((AccelerometerDriver *)self, accelerometerCtrl, (AccelerometerDriver_runFun)RealAccelerometerDriver_run);
    return self;
}

void RealAccelerometerDriver_run(RealAccelerometerDriver * const self) {
    if (self->accelerometerDriver.isDataAvailable) {
        printf("RealAccelerometerDriver_readData\n");
        self->accelerometerDriver.isDataAvailable = false;
        AccelerometerCtrl_onDataReceived(
            self->accelerometerDriver.accelerometerCtrl,
            &(Acceleration3d){
                .x = 1,
                .y = 2,
                .z = 3,
            }
        );
    }
}