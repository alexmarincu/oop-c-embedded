#include "AccelCtrl.h"
#include <stdio.h>

struct AccelCtrl {
    AccelDriver * accelDriver;
};

AccelCtrl * AccelCtrl_getInstance(void) {
    static AccelCtrl self;
    return &self;
}

void AccelCtrl_init(AccelCtrl * const self, AccelDriver * const accelDriver) {
    self->accelDriver = accelDriver;
}

void AccelCtrl_main(AccelCtrl * const self) {
    if (self->accelDriver->dataAvailable) {
        AccelDriver_AccelDataIn001G accelDataIn001G;
        AccelDriver_readData(self->accelDriver, &accelDataIn001G);
        printf("x=%d, y=%d, z=%d\n", accelDataIn001G.x, accelDataIn001G.y, accelDataIn001G.z);
    }
}

void AccelCtrl_setAccelDriver(AccelCtrl * const self, AccelDriver * const accelDriver) {
    self->accelDriver = accelDriver;
}
