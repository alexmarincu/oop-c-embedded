#include "SimAccelDriver.h"

struct SimAccelDriver {
    AccelDriver accelDriver;
};

static AccelDriver_AccelDataIn001G * SimAccelDriver_readData(
    SimAccelDriver * const self, AccelDriver_AccelDataIn001G * const accelDataIn001G
);

SimAccelDriver * SimAccelDriver_init(SimAccelDriver * const self) {
    AccelDriver_init((AccelDriver *)self, (AccelDriver_readDataFun)SimAccelDriver_readData);
    return self;
}

SimAccelDriver * SimAccelDriver_getInstance(void) {
    static SimAccelDriver self;
    return &self;
}

AccelDriver_AccelDataIn001G * SimAccelDriver_readData(
    SimAccelDriver * const self, AccelDriver_AccelDataIn001G * const accelDataIn001G
) {
    self->accelDriver.dataAvailable = false;
    *accelDataIn001G = (AccelDriver_AccelDataIn001G){
        .x = 100,
        .y = 200,
        .z = 300
    };
    return accelDataIn001G;
}