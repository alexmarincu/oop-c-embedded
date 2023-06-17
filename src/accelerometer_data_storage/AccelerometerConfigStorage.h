#ifndef AccelerometerConfigStorage_h
#define AccelerometerConfigStorage_h
#include "../accelerometer_data_models/AccelerometerConfig.h"
#include "../accelerometer_data_models/AccelerometerConfigDao.h"

typedef struct AccelerometerConfigStorage AccelerometerConfigStorage;

AccelerometerConfigStorage * AccelerometerConfigStorage_getInstance(void);
AccelerometerConfigStorage * AccelerometerConfigStorage_init(AccelerometerConfigStorage * const self);
AccelerometerConfigDao * AccelerometerConfigStorage_getAccelerometerConfigDao(AccelerometerConfigStorage * const self);
void AccelerometerConfigStorage_write(AccelerometerConfigStorage * const self, AccelerometerConfig * const accelerometerConfig);
AccelerometerConfig * AccelerometerConfigStorage_read(
    AccelerometerConfigStorage * const self, AccelerometerConfig * const accelerometerConfig
);

#endif // AccelerometerConfigStorage_h
