#include "AccelerometerCtrl.h"
#include <stdio.h>

struct AccelerometerCtrl {
    MotionDetector * motionDetector;
};

AccelerometerCtrl * AccelerometerCtrl_getInstance(void) {
    static AccelerometerCtrl self;
    return &self;
}

AccelerometerCtrl * AccelerometerCtrl_init(AccelerometerCtrl * const self, MotionDetector * const motionDetector) {
    self->motionDetector = motionDetector;
    return self;
}

void AccelerometerCtrl_onDataReceived(AccelerometerCtrl * const self, Acceleration3d * const acceleration3dIn098mg) {
    printf("x = %d, y = %d, z = %d\n", acceleration3dIn098mg->x, acceleration3dIn098mg->y, acceleration3dIn098mg->z);
    MotionDetector_processAcceleration3d(self->motionDetector, acceleration3dIn098mg);
}
