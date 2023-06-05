#include "PlatformAccSimDriver.h"
#include <stdio.h>

struct PlatformAccSimDriver {
    AccDriver accDriver;
};

static AccDriver_AccDataIn001g * PlatformAccSimDriver_readData(
    PlatformAccSimDriver * const self, AccDriver_AccDataIn001g * const accDataIn001g
);

PlatformAccSimDriver * PlatformAccSimDriver_init(PlatformAccSimDriver * const self) {
    AccDriver_init((AccDriver *)self, (AccDriver_readDataFun)PlatformAccSimDriver_readData);
    return self;
}

PlatformAccSimDriver * PlatformAccSimDriver_getInstance(void) {
    static PlatformAccSimDriver self;
    return &self;
}

AccDriver_AccDataIn001g * PlatformAccSimDriver_readData(
    PlatformAccSimDriver * const self, AccDriver_AccDataIn001g * const accDataIn001g
) {
    self->accDriver.isDataAvailable = false;
    *accDataIn001g = (AccDriver_AccDataIn001g){
        .x = 100,
        .y = 200,
        .z = 300
    };
    printf("PlatformAccSimDriver_readData\n");
    return accDataIn001g;
}