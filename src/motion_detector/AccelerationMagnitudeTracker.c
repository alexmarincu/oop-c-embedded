#include "AccelerationMagnitudeTracker.h"
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

AccelerationMagnitudeTracker * AccelerationMagnitudeTracker_init(AccelerationMagnitudeTracker * const self) {
    memset(self->accelerationMagnitudesIn098mg, 0, sizeof(self->accelerationMagnitudesIn098mg));
    self->count = 0;
    return self;
}

void AccelerationMagnitudeTracker_add(AccelerationMagnitudeTracker * const self, uint16_t const accelerationMagnitudeIn098mg) {
    for (uint8_t i = min(self->count, AccelerationMagnitudeTracker_valuesMaxCount - 1); i > 0; i--) {
        self->accelerationMagnitudesIn098mg[i] = self->accelerationMagnitudesIn098mg[i - 1];
    }
    self->accelerationMagnitudesIn098mg[0] = accelerationMagnitudeIn098mg;
    if (self->count < AccelerationMagnitudeTracker_valuesMaxCount) {
        self->count++;
    }
}

uint16_t AccelerationMagnitudeTracker_getElement(AccelerationMagnitudeTracker * const self, uint8_t const index) {
    return self->accelerationMagnitudesIn098mg[index];
}

bool AccelerationMagnitudeTracker_isFull(AccelerationMagnitudeTracker * const self) {
    return (self->count == AccelerationMagnitudeTracker_valuesMaxCount);
}
