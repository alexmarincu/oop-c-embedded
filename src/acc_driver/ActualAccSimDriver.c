#include "ActualAccSimDriver.h"
#include "../acceleration/Acceleration3d.h"
#include "AccDriver.h"
#include <stdio.h>

struct ActualAccSimDriver {
    AccDriver accDriver;
};

ActualAccSimDriver * ActualAccSimDriver_getInstance(void) {
    static ActualAccSimDriver self;
    return &self;
}

ActualAccSimDriver * ActualAccSimDriver_init(ActualAccSimDriver * const self, AccCtrl * const accCtrl) {
    AccDriver_init((AccDriver *)self, accCtrl, (AccDriver_runFun)ActualAccSimDriver_run);
    return self;
}

void ActualAccSimDriver_run(ActualAccSimDriver * const self) {
    if (self->accDriver.isDataAvailable) {
        printf("ActualAccSimDriver_readData\n");
        self->accDriver.isDataAvailable = false;
        AccCtrl_onDataReceived(
            self->accDriver.accCtrl,
            &(Acceleration3d){
                .x = 100,
                .y = 200,
                .z = 300,
            }
        );
    }
}
