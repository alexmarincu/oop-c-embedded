#include "AccDriver.h"

AccDriver * AccDriver_init(AccDriver * const self, AccDriver_readDataFun const readData) {
    self->isDataAvailable = false;
    self->readData = readData;
    return self;
}

void AccDriver_onDataAvailableInt(AccDriver * const self) {
    self->isDataAvailable = true;
}

AccDriver_AccDataIn001g * AccDriver_readData(
    AccDriver * const self, AccDriver_AccDataIn001g * const accDataIn001g
) {
    return self->readData(self, accDataIn001g);
}

bool AccDriver_isDataAvailable(AccDriver const * const self) {
    return self->isDataAvailable;
}