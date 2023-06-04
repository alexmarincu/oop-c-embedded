#ifndef AccelDriver_h
#define AccelDriver_h
#include <stdbool.h>
#include <stdint.h>

typedef struct AccelDriver AccelDriver;
typedef struct AccelDriver_AccelDataIn001G AccelDriver_AccelDataIn001G;
typedef AccelDriver_AccelDataIn001G * (*AccelDriver_readDataFun)(
    AccelDriver * const self, AccelDriver_AccelDataIn001G * const accelDataIn001G
);

struct AccelDriver {
    bool dataAvailable;
    AccelDriver_readDataFun readData;
};

struct AccelDriver_AccelDataIn001G {
    uint32_t x;
    uint32_t y;
    uint32_t z;
};

AccelDriver * AccelDriver_init(AccelDriver * const self, AccelDriver_readDataFun const readData);
void AccelDriver_dataAvailableInt(AccelDriver * const self);
bool AccelDriver_isDataAvailable(AccelDriver const * const self);
AccelDriver_AccelDataIn001G * AccelDriver_readData(
    AccelDriver * const self, AccelDriver_AccelDataIn001G * const accelDataIn001G
);

#endif // AccelDriver_h
