#include "AccelerometerSimulatorDriver.h"
#include "../../../accelerometer_data_models/src/Acceleration3d.h"
#include "AccelerometerCtrl.h"
#include "AccelerometerDriver.h"
#include <stdio.h>

struct AccelerometerSimulatorDriver {
    AccelerometerDriver accelerometerDriver;
};

AccelerometerSimulatorDriver * AccelerometerSimulatorDriver_getInstance(void) {
    static AccelerometerSimulatorDriver self;
    return &self;
}

AccelerometerSimulatorDriver * AccelerometerSimulatorDriver_init(AccelerometerSimulatorDriver * const self) {
    AccelerometerDriver_init((AccelerometerDriver *)self, (AccelerometerDriver_mainFun)AccelerometerSimulatorDriver_main);
    return self;
}

void AccelerometerSimulatorDriver_main(AccelerometerSimulatorDriver * const self) {
    if (self->accelerometerDriver.isDataAvailable) {
        printf("AccelerometerSimulatorDriver_readData\n");
        self->accelerometerDriver.isDataAvailable = false;
        AccelerometerCtrl_onDataReceived(
            &(Acceleration3d){
                .x = 100,
                .y = 200,
                .z = 300,
            }
        );
    }
}
