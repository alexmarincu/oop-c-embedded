#ifndef AccelerationMagnitudeTracker_h
#define AccelerationMagnitudeTracker_h
#include <stdbool.h>
#include <stdint.h>

#define AccelerationMagnitudeTracker_valuesMaxCount 2u

typedef struct AccelerationMagnitudeTracker AccelerationMagnitudeTracker;
struct AccelerationMagnitudeTracker {
    uint16_t accelerationMagnitudesIn098mg[AccelerationMagnitudeTracker_valuesMaxCount];
    uint8_t count;
};

AccelerationMagnitudeTracker * AccelerationMagnitudeTracker_init(AccelerationMagnitudeTracker * const self);
void AccelerationMagnitudeTracker_add(AccelerationMagnitudeTracker * const self, uint16_t const accelerationMagnitudeIn098mg);
uint16_t AccelerationMagnitudeTracker_getElement(AccelerationMagnitudeTracker * const self, uint8_t const index);
bool AccelerationMagnitudeTracker_isFull(AccelerationMagnitudeTracker * const self);

#endif // AccelerationMagnitudeTracker_h
