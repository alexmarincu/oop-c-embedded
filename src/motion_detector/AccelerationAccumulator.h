#ifndef AccelerationAccumulator_h
#define AccelerationAccumulator_h
#include "../acceleration/Acceleration3d.h"

typedef struct AccelerationAccumulator AccelerationAccumulator;
struct AccelerationAccumulator {
    Acceleration3d cumulatedValueIn098mg;
    uint8_t samplesCount;
};

AccelerationAccumulator * AccelerationAccumulator_init(AccelerationAccumulator * const self);
void AccelerationAccumulator_cumulate(AccelerationAccumulator * const self, Acceleration3d * const acceleration3dIn098mg);
void AccelerationAccumulator_reset(AccelerationAccumulator * const self);
Acceleration3d * AccelerationAccumulator_calculateAverage(AccelerationAccumulator * const self, Acceleration3d * const averageAcceleration3d);

#endif // AccelerationAccumulator_h
