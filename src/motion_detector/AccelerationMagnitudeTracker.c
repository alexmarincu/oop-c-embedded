#include "AccelerationMagnitudeTracker.h"
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

AccelerationMagnitudeTracker * AccelerationMagnitudeTracker_init(AccelerationMagnitudeTracker * const self) {
    memset(self->valuesIn098mg, 0, sizeof(self->valuesIn098mg));
    self->valuesCount = 0;
    return self;
}

void AccelerationMagnitudeTracker_add(AccelerationMagnitudeTracker * const self, uint16_t const accelerationMagnitudeIn098mg) {
    for (uint8_t i = min(self->valuesCount, AccelerationMagnitudeTracker_valuesMaxCount - 1); i > 0; i--) {
        self->valuesIn098mg[i] = self->valuesIn098mg[i - 1];
    }
    self->valuesIn098mg[0] = accelerationMagnitudeIn098mg;
    if (self->valuesCount < AccelerationMagnitudeTracker_valuesMaxCount) {
        self->valuesCount++;
    }
}

uint16_t AccelerationMagnitudeTracker_getElement(AccelerationMagnitudeTracker * const self, uint8_t const index) {
    return self->valuesIn098mg[index];
}

bool AccelerationMagnitudeTracker_isFull(AccelerationMagnitudeTracker * const self) {
    return (self->valuesCount == AccelerationMagnitudeTracker_valuesMaxCount);
}
