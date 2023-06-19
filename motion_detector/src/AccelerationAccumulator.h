#ifndef AccelerationAccumulator_h
#define AccelerationAccumulator_h
#include "../../accelerometer_data_models/src/Acceleration3d.h"

typedef struct AccelerationAccumulator AccelerationAccumulator;
struct AccelerationAccumulator {
    Acceleration3d accumulatedAcceleration3dIn098mg;
    uint8_t count;
};

AccelerationAccumulator * AccelerationAccumulator_init(AccelerationAccumulator * const self);
void AccelerationAccumulator_accumulate(AccelerationAccumulator * const self, Acceleration3d * const acceleration3dIn098mg);
void AccelerationAccumulator_reset(AccelerationAccumulator * const self);
Acceleration3d * AccelerationAccumulator_calculateAverage(
    AccelerationAccumulator * const self, Acceleration3d * const acceleration3dIn098mg
);

#endif // AccelerationAccumulator_h
