#include "AccelerometerSimulatorDriver.h"
#include "../accelerometer_data_models/Acceleration3d.h"
#include "AccelerometerDriver.h"
#include <stdio.h>

struct AccelerometerSimulatorDriver {
    AccelerometerDriver accelerometerDriver;
};

AccelerometerSimulatorDriver * AccelerometerSimulatorDriver_getInstance(void) {
    static AccelerometerSimulatorDriver self;
    return &self;
}

AccelerometerSimulatorDriver * AccelerometerSimulatorDriver_init(
    AccelerometerSimulatorDriver * const self, AccelerometerCtrl * const accelerometerCtrl
) {
    AccelerometerDriver_init((AccelerometerDriver *)self, accelerometerCtrl, (AccelerometerDriver_runFun)AccelerometerSimulatorDriver_run);
    return self;
}

void AccelerometerSimulatorDriver_run(AccelerometerSimulatorDriver * const self) {
    if (self->accelerometerDriver.isDataAvailable) {
        printf("AccelerometerSimulatorDriver_readData\n");
        self->accelerometerDriver.isDataAvailable = false;
        AccelerometerCtrl_onDataReceived(
            self->accelerometerDriver.accelerometerCtrl,
            &(Acceleration3d){
                .x = 100,
                .y = 200,
                .z = 300,
            }
        );
    }
}
