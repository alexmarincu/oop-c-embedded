#ifndef AccelerometerSimulatorDriver_h
#define AccelerometerSimulatorDriver_h

typedef struct AccelerometerSimulatorDriver AccelerometerSimulatorDriver;

AccelerometerSimulatorDriver * AccelerometerSimulatorDriver_getInstance(void);
AccelerometerSimulatorDriver * AccelerometerSimulatorDriver_init(AccelerometerSimulatorDriver * const self);
void AccelerometerSimulatorDriver_run(AccelerometerSimulatorDriver * const self);

#endif // AccelerometerSimulatorDriver_h
