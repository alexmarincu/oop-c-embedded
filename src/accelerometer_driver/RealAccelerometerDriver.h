#ifndef RealAccelerometerDriver_h
#define RealAccelerometerDriver_h
#include "../accelerometer_controller/AccelerometerCtrl.h"

typedef struct RealAccelerometerDriver RealAccelerometerDriver;

RealAccelerometerDriver * RealAccelerometerDriver_getInstance(void);
RealAccelerometerDriver * RealAccelerometerDriver_init(
    RealAccelerometerDriver * const self, AccelerometerCtrl * const accelerometerCtrl
);
void RealAccelerometerDriver_run(RealAccelerometerDriver * const self);

#endif // RealAccelerometerDriver_h
