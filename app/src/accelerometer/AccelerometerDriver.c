#include "AccelerometerDriver.h"

AccelerometerDriver * AccelerometerDriver_init(
    AccelerometerDriver * const self, AccelerometerDriver_runFun const run
) {
    self->run = run;
    self->isDataAvailable = false;
    return self;
}

void AccelerometerDriver_dataAvailableInt(AccelerometerDriver * const self) {
    self->isDataAvailable = true;
}

void AccelerometerDriver_run(AccelerometerDriver * const self) {
    return self->run(self);
}
