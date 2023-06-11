#include "AccelerationAccumulator.h"

AccelerationAccumulator * AccelerationAccumulator_init(AccelerationAccumulator * const self) {
    self->cumulatedValueIn098mg = (Acceleration3d){ 0 };
    self->samplesCount = 0;
    return self;
}

void AccelerationAccumulator_cumulate(AccelerationAccumulator * const self, Acceleration3d * const acceleration3dIn098mg) {
    Acceleration3d_plus(&self->cumulatedValueIn098mg, acceleration3dIn098mg);
    self->samplesCount++;
}

void AccelerationAccumulator_reset(AccelerationAccumulator * const self) {
    AccelerationAccumulator_init(self);
}

Acceleration3d * AccelerationAccumulator_calculateAverage(AccelerationAccumulator * const self, Acceleration3d * const averageAcceleration3d) {
    *averageAcceleration3d = self->cumulatedValueIn098mg;
    if (self->samplesCount > 0) {
        *averageAcceleration3d = *Acceleration3d_div(averageAcceleration3d, self->samplesCount);
    }
    return averageAcceleration3d;
}
