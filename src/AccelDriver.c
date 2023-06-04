#include "AccelDriver.h"

AccelDriver * AccelDriver_init(AccelDriver * const self, AccelDriver_readDataFun const readData) {
    self->dataAvailable = false;
    self->readData = readData;
    return self;
}

void AccelDriver_dataAvailableInt(AccelDriver * const self) {
    self->dataAvailable = true;
}

AccelDriver_AccelDataIn001G * AccelDriver_readData(
    AccelDriver * const self, AccelDriver_AccelDataIn001G * const accelDataIn001G
) {
    return self->readData(self, accelDataIn001G);
}

bool AccelDriver_isDataAvailable(AccelDriver const * const self) {
    return self->dataAvailable;
}