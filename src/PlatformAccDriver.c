#include "PlatformAccDriver.h"
#include <stdio.h>

struct PlatformAccDriver {
    AccDriver accDriver;
};

static AccDriver_AccDataIn001g * PlatformAccDriver_readData(
    PlatformAccDriver * const self, AccDriver_AccDataIn001g * const accDataIn001g
);

PlatformAccDriver * PlatformAccDriver_init(PlatformAccDriver * const self) {
    AccDriver_init((AccDriver *)self, (AccDriver_readDataFun)PlatformAccDriver_readData);
    return self;
}

PlatformAccDriver * PlatformAccDriver_getInstance(void) {
    static PlatformAccDriver self;
    return &self;
}

AccDriver_AccDataIn001g * PlatformAccDriver_readData(
    PlatformAccDriver * const self, AccDriver_AccDataIn001g * const accDataIn001g
) {
    self->accDriver.isDataAvailable = false;
    *accDataIn001g = (AccDriver_AccDataIn001g){
        .x = 1,
        .y = 2,
        .z = 3
    };
    printf("PlatformAccDriver_readData\n");
    return accDataIn001g;
}