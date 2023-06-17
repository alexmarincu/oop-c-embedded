#ifndef AccelerometerConfigurator_h
#define AccelerometerConfigurator_h
#include "../accelerometer_data_models/AccelerometerConfigDao.h"

typedef struct AccelerometerConfigurator AccelerometerConfigurator;

AccelerometerConfigurator * AccelerometerConfigurator_getInstance(void);
AccelerometerConfigurator * AccelerometerConfigurator_init(
    AccelerometerConfigurator * const self, AccelerometerConfigDao * const accelerometerConfigDao
);
void AccelerometerConfigurator_toggleAccelerometerDriver(AccelerometerConfigurator * const self);

#endif // AccelerometerConfigurator_H
