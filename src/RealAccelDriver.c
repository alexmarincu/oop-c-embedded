#include "RealAccelDriver.h"

struct RealAccelDriver {
    AccelDriver accelDriver;
};

static AccelDriver_AccelDataIn001G * RealAccelDriver_readData(
    RealAccelDriver * const self, AccelDriver_AccelDataIn001G * const accelDataIn001G
);

RealAccelDriver * RealAccelDriver_init(RealAccelDriver * const self) {
    AccelDriver_init((AccelDriver *)self, (AccelDriver_readDataFun)RealAccelDriver_readData);
    return self;
}

RealAccelDriver * RealAccelDriver_getInstance(void) {
    static RealAccelDriver self;
    return &self;
}

AccelDriver_AccelDataIn001G * RealAccelDriver_readData(
    RealAccelDriver * const self, AccelDriver_AccelDataIn001G * const accelDataIn001G
) {
    self->accelDriver.dataAvailable = false;
    *accelDataIn001G = (AccelDriver_AccelDataIn001G){
        .x = 1,
        .y = 2,
        .z = 3
    };
    return accelDataIn001G;
}