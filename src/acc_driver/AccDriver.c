#include "AccDriver.h"

AccDriver * AccDriver_init(AccDriver * const self, AccCtrl * const accCtrl, AccDriver_runFun const run) {
    self->accCtrl = accCtrl;
    self->run = run;
    self->isDataAvailable = false;
    return self;
}

void AccDriver_dataAvailableInt(AccDriver * const self) {
    self->isDataAvailable = true;
}

void AccDriver_run(AccDriver * const self) {
    return self->run(self);
}
