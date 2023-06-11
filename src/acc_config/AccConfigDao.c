#include "AccConfigDao.h"

AccConfigDao * AccConfigDao_init(
    AccConfigDao * const self, void * const impl, AccConfigDao_writeFun const write, AccConfigDao_readFun const read
) {
    self->impl = impl;
    self->write = write;
    self->read = read;
    return self;
}

void AccConfigDao_write(AccConfigDao * const self, AccConfig * const accConfig) {
    return self->write(self->impl, accConfig);
}

AccConfig * AccConfigDao_read(AccConfigDao * const self, AccConfig * const accConfig) {
    return self->read(self->impl, accConfig);
}
