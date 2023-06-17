#include "AccelerometerConfigDao.h"

AccelerometerConfigDao * AccelerometerConfigDao_init(
    AccelerometerConfigDao * const self, void * const impl,
    AccelerometerConfigDao_writeFun const write, AccelerometerConfigDao_readFun const read
) {
    self->impl = impl;
    self->write = write;
    self->read = read;
    return self;
}

void AccelerometerConfigDao_write(AccelerometerConfigDao * const self, AccelerometerConfig * const accelerometerConfig) {
    return self->write(self->impl, accelerometerConfig);
}

AccelerometerConfig * AccelerometerConfigDao_read(AccelerometerConfigDao * const self, AccelerometerConfig * const accelerometerConfig) {
    return self->read(self->impl, accelerometerConfig);
}
