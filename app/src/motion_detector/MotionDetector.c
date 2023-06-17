#include "MotionDetector.h"
#include "../../../lib/src/timer/Timer.h"
#include "AccelerationAccumulator.h"
#include "AccelerationMagnitudeTracker.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

struct MotionDetector {
    bool isMoving;
    AccelerationAccumulator accelerationAccumulator;
    AccelerationMagnitudeTracker accelerationMagnitudeTracker;
    Timer averageAccelerationCalculationTimer;
    uint16_t const averageAccelerationCalculationTimerDurationIn1ms;
};

MotionDetector * MotionDetector_getInstance(void) {
    static MotionDetector self = { .averageAccelerationCalculationTimerDurationIn1ms = 1000 };
    return &self;
}

MotionDetector * MotionDetector_init(MotionDetector * const self) {
    self->isMoving = false;
    self->accelerationAccumulator = (AccelerationAccumulator){ 0 };
    self->accelerationMagnitudeTracker = (AccelerationMagnitudeTracker){ 0 };
    Timer_start(Timer_init(&self->averageAccelerationCalculationTimer), self->averageAccelerationCalculationTimerDurationIn1ms);
    return self;
}

void MotionDetector_run(MotionDetector * const self) {
    if (Timer_isExpired(&self->averageAccelerationCalculationTimer)) {
        Timer_start(&self->averageAccelerationCalculationTimer, self->averageAccelerationCalculationTimerDurationIn1ms);
        uint16_t const accelerationMagnitudeIn098mg =
            Acceleration3d_magnitude(AccelerationAccumulator_calculateAverage(&self->accelerationAccumulator, &(Acceleration3d){ 0 }));
        AccelerationAccumulator_reset(&self->accelerationAccumulator);
        printf("accelerationMagnitudeIn098mg = %d\n", accelerationMagnitudeIn098mg);
        if (AccelerationMagnitudeTracker_isFull(&self->accelerationMagnitudeTracker)) {
            self->isMoving =
                ((((int16_t)accelerationMagnitudeIn098mg - (int16_t)AccelerationMagnitudeTracker_getElement(&self->accelerationMagnitudeTracker, 0)) > 100) ||
                 (((int16_t)accelerationMagnitudeIn098mg - (int16_t)AccelerationMagnitudeTracker_getElement(&self->accelerationMagnitudeTracker, 0)) < -100)) &&
                ((((int16_t)accelerationMagnitudeIn098mg - (int16_t)AccelerationMagnitudeTracker_getElement(&self->accelerationMagnitudeTracker, 1)) > 200) ||
                 (((int16_t)accelerationMagnitudeIn098mg - (int16_t)AccelerationMagnitudeTracker_getElement(&self->accelerationMagnitudeTracker, 1)) < -200));
            printf("isMoving = %d\n", self->isMoving);
        }
        AccelerationMagnitudeTracker_add(&self->accelerationMagnitudeTracker, accelerationMagnitudeIn098mg);
    }
}

void MotionDetector_processAcceleration3d(MotionDetector * const self, Acceleration3d * const acceleration3dIn098mg) {
    AccelerationAccumulator_accumulate(&self->accelerationAccumulator, acceleration3dIn098mg);
}
