#ifndef AccDriver_h
#define AccDriver_h
#include <stdbool.h>
#include <stdint.h>

typedef struct AccDriver AccDriver;
typedef struct AccDriver_AccDataIn001g AccDriver_AccDataIn001g;
typedef AccDriver_AccDataIn001g * (*AccDriver_readDataFun)(
    AccDriver * const self, AccDriver_AccDataIn001g * const accDataIn001g
);

struct AccDriver {
    bool dataAvailable;
    AccDriver_readDataFun readData;
};

struct AccDriver_AccDataIn001g {
    uint32_t x;
    uint32_t y;
    uint32_t z;
};

AccDriver * AccDriver_init(AccDriver * const self, AccDriver_readDataFun const readData);
void AccDriver_dataAvailableInt(AccDriver * const self);
bool AccDriver_isDataAvailable(AccDriver const * const self);
AccDriver_AccDataIn001g * AccDriver_readData(
    AccDriver * const self, AccDriver_AccDataIn001g * const accDataIn001g
);

#endif // AccDriver_h
