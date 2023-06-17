#include "AccelerationAccumulator.h"

AccelerationAccumulator * AccelerationAccumulator_init(AccelerationAccumulator * const self) {
    self->accumulatedAcceleration3dIn098mg = (Acceleration3d){ 0 };
    self->count = 0;
    return self;
}

void AccelerationAccumulator_accumulate(AccelerationAccumulator * const self, Acceleration3d * const acceleration3dIn098mg) {
    Acceleration3d_plus(&self->accumulatedAcceleration3dIn098mg, acceleration3dIn098mg);
    self->count++;
}

void AccelerationAccumulator_reset(AccelerationAccumulator * const self) {
    AccelerationAccumulator_init(self);
}

Acceleration3d * AccelerationAccumulator_calculateAverage(
    AccelerationAccumulator * const self, Acceleration3d * const acceleration3dIn098mg
) {
    *acceleration3dIn098mg = self->accumulatedAcceleration3dIn098mg;
    if (self->count > 0) {
        *acceleration3dIn098mg = *Acceleration3d_div(acceleration3dIn098mg, self->count);
    }
    return acceleration3dIn098mg;
}
