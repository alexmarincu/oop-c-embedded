#include "RealAccelerometerDriver.h"
#include "AccelerometerCtrl.h"
#include "AccelerometerDriver.h"
#include <stdio.h>

struct RealAccelerometerDriver {
    AccelerometerDriver accelerometerDriver;
};

RealAccelerometerDriver * RealAccelerometerDriver_getInstance(void) {
    static RealAccelerometerDriver self;
    return &self;
}

RealAccelerometerDriver * RealAccelerometerDriver_init(RealAccelerometerDriver * const self) {
    AccelerometerDriver_init((AccelerometerDriver *)self, (AccelerometerDriver_mainFun)RealAccelerometerDriver_main);
    return self;
}

void RealAccelerometerDriver_main(RealAccelerometerDriver * const self) {
    if (self->accelerometerDriver.isDataAvailable) {
        printf("RealAccelerometerDriver_readData\n");
        self->accelerometerDriver.isDataAvailable = false;
        AccelerometerCtrl_onDataReceived(
            &(Acceleration3d){
                .x = 1,
                .y = 2,
                .z = 3,
            }
        );
    }
}