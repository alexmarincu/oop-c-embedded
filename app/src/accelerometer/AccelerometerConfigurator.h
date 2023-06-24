#ifndef AccelerometerConfigurator_h
#define AccelerometerConfigurator_h
#include "../../../accelerometer_data_models/src/AccelerometerConfigDao.h"

void AccelerometerConfigurator_init(AccelerometerConfigDao * const accelerometerConfigDao);
void AccelerometerConfigurator_toggleAccelerometerDriver(void);

#endif // AccelerometerConfigurator_H
