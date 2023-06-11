#ifndef AccConfigDao_h
#define AccConfigDao_h
#include "AccConfig.h"

typedef struct AccConfigDao AccConfigDao;
typedef void (*AccConfigDao_writeFun)(AccConfigDao * const self, AccConfig * const accConfig);
typedef AccConfig * (*AccConfigDao_readFun)(AccConfigDao * const self, AccConfig * const accConfig);
struct AccConfigDao {
    void * impl;
    AccConfigDao_writeFun write;
    AccConfigDao_readFun read;
};

AccConfigDao * AccConfigDao_init(
    AccConfigDao * const self, void * const impl, AccConfigDao_writeFun const write, AccConfigDao_readFun const read
);
void AccConfigDao_write(AccConfigDao * const self, AccConfig * const accConfig);
AccConfig * AccConfigDao_read(AccConfigDao * const self, AccConfig * const accConfig);

#endif // AccConfigDao_h
