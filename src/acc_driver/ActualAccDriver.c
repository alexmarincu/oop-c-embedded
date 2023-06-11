#include "ActualAccDriver.h"
#include "AccDriver.h"
#include <stdio.h>

struct ActualAccDriver {
    AccDriver accDriver;
};

ActualAccDriver * ActualAccDriver_getInstance(void) {
    static ActualAccDriver self;
    return &self;
}

ActualAccDriver * ActualAccDriver_init(ActualAccDriver * const self, AccCtrl * const accCtrl) {
    AccDriver_init((AccDriver *)self, accCtrl, (AccDriver_runFun)ActualAccDriver_run);
    return self;
}

void ActualAccDriver_run(ActualAccDriver * const self) {
    if (self->accDriver.isDataAvailable) {
        printf("ActualAccDriver_readData\n");
        self->accDriver.isDataAvailable = false;
        AccCtrl_onDataReceived(
            self->accDriver.accCtrl,
            &(Acceleration3d){
                .x = 1,
                .y = 2,
                .z = 3,
            }
        );
    }
}