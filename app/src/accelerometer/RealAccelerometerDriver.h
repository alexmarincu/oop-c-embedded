#ifndef RealAccelerometerDriver_h
#define RealAccelerometerDriver_h

typedef struct RealAccelerometerDriver RealAccelerometerDriver;

RealAccelerometerDriver * RealAccelerometerDriver_getInstance(void);
RealAccelerometerDriver * RealAccelerometerDriver_init(RealAccelerometerDriver * const self);
void RealAccelerometerDriver_run(RealAccelerometerDriver * const self);

#endif // RealAccelerometerDriver_h
