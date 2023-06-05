#include "AccCtrl.h"
#include <stdio.h>

struct AccCtrl {
    AccDriver * accDriver;
};

AccCtrl * AccCtrl_getInstance(void) {
    static AccCtrl self;
    return &self;
}

void AccCtrl_init(AccCtrl * const self, AccDriver * const accDriver) {
    self->accDriver = accDriver;
}

void AccCtrl_run(AccCtrl * const self) {
    if (AccDriver_isDataAvailable(self->accDriver)) {
        AccDriver_AccDataIn001g const * const accDataIn001g = AccDriver_readData(
            self->accDriver,
            &(AccDriver_AccDataIn001g){}
        );
        printf("x=%d, y=%d, z=%d\n", accDataIn001g->x, accDataIn001g->y, accDataIn001g->z);
    }
}

void AccCtrl_setAccDriver(AccCtrl * const self, AccDriver * const accDriver) {
    self->accDriver = accDriver;
}
