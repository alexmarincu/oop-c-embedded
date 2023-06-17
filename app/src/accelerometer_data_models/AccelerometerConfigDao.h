#ifndef AccelerometerConfigDao_h
#define AccelerometerConfigDao_h
#include "AccelerometerConfig.h"

typedef struct AccelerometerConfigDao AccelerometerConfigDao;
typedef void (*AccelerometerConfigDao_writeFun)(AccelerometerConfigDao * const self, AccelerometerConfig * const accelerometerConfig);
typedef AccelerometerConfig * (*AccelerometerConfigDao_readFun)(
    AccelerometerConfigDao * const self, AccelerometerConfig * const accelerometerConfig
);
struct AccelerometerConfigDao {
    void * impl;
    AccelerometerConfigDao_writeFun write;
    AccelerometerConfigDao_readFun read;
};

AccelerometerConfigDao * AccelerometerConfigDao_init(
    AccelerometerConfigDao * const self, void * const impl,
    AccelerometerConfigDao_writeFun const write, AccelerometerConfigDao_readFun const read
);
void AccelerometerConfigDao_write(AccelerometerConfigDao * const self, AccelerometerConfig * const accelerometerConfig);
AccelerometerConfig * AccelerometerConfigDao_read(AccelerometerConfigDao * const self, AccelerometerConfig * const accelerometerConfig);

#endif // AccelerometerConfigDao_h
