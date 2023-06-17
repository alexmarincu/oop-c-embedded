#ifndef AccelerometerDriverProvider_h
#define AccelerometerDriverProvider_h
#include "AccelerometerDriver.h"

typedef struct AccelerometerDriverProvider AccelerometerDriverProvider;

AccelerometerDriverProvider * AccelerometerDriverProvider_getInstance(void);
AccelerometerDriverProvider * AccelerometerDriverProvider_init(AccelerometerDriverProvider * const self);
AccelerometerDriver * AccelerometerDriverProvider_getCurrentAccelerometerDriver(AccelerometerDriverProvider * const self);

#endif // AccelerometerDriverProvider_h
