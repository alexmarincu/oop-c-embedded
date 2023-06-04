#include "RealAccDriver.h"
#include <stdio.h>

struct RealAccDriver {
    AccDriver accDriver;
};

static AccDriver_AccDataIn001g * RealAccDriver_readData(
    RealAccDriver * const self, AccDriver_AccDataIn001g * const accDataIn001g
);

RealAccDriver * RealAccDriver_init(RealAccDriver * const self) {
    AccDriver_init((AccDriver *)self, (AccDriver_readDataFun)RealAccDriver_readData);
    return self;
}

RealAccDriver * RealAccDriver_getInstance(void) {
    static RealAccDriver self;
    return &self;
}

AccDriver_AccDataIn001g * RealAccDriver_readData(
    RealAccDriver * const self, AccDriver_AccDataIn001g * const accDataIn001g
) {
    self->accDriver.dataAvailable = false;
    *accDataIn001g = (AccDriver_AccDataIn001g){
        .x = 1,
        .y = 2,
        .z = 3
    };
    printf("RealAccDriver_readData\n");
    return accDataIn001g;
}