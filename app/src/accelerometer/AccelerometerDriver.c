#include "AccelerometerDriver.h"

AccelerometerDriver * AccelerometerDriver_init(
    AccelerometerDriver * const self, AccelerometerDriver_mainFun const main
) {
    self->main = main;
    self->isDataAvailable = false;
    return self;
}

void AccelerometerDriver_dataAvailableInt(AccelerometerDriver * const self) {
    self->isDataAvailable = true;
}

void AccelerometerDriver_main(AccelerometerDriver * const self) {
    return self->main(self);
}
