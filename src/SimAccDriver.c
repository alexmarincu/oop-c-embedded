#include "SimAccDriver.h"
#include <stdio.h>

struct SimAccDriver {
    AccDriver accDriver;
};

static AccDriver_AccDataIn001g * SimAccDriver_readData(
    SimAccDriver * const self, AccDriver_AccDataIn001g * const accDataIn001g
);

SimAccDriver * SimAccDriver_init(SimAccDriver * const self) {
    AccDriver_init((AccDriver *)self, (AccDriver_readDataFun)SimAccDriver_readData);
    return self;
}

SimAccDriver * SimAccDriver_getInstance(void) {
    static SimAccDriver self;
    return &self;
}

AccDriver_AccDataIn001g * SimAccDriver_readData(
    SimAccDriver * const self, AccDriver_AccDataIn001g * const accDataIn001g
) {
    self->accDriver.dataAvailable = false;
    *accDataIn001g = (AccDriver_AccDataIn001g){
        .x = 100,
        .y = 200,
        .z = 300
    };
    printf("SimAccDriver_readData\n");
    return accDataIn001g;
}