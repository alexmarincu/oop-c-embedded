#ifndef AccelerometerDriverProvider_h
#define AccelerometerDriverProvider_h
#include "AccelerometerDriver.h"

void AccelerometerDriverProvider_init(void);
AccelerometerDriver * AccelerometerDriverProvider_getCurrentAccelerometerDriver(void);

#endif // AccelerometerDriverProvider_h
