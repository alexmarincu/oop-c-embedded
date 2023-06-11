#include "AccCtrl.h"
#include <stdio.h>

struct AccCtrl {
    MotionDetector * motionDetector;
};

AccCtrl * AccCtrl_getInstance(void) {
    static AccCtrl self;
    return &self;
}

AccCtrl * AccCtrl_init(AccCtrl * const self, MotionDetector * const motionDetector) {
    self->motionDetector = motionDetector;
    return self;
}

void AccCtrl_onDataReceived(AccCtrl * const self, Acceleration3d * const acceleration3dIn098mg) {
    printf("x = %d, y = %d, z = %d\n", acceleration3dIn098mg->x, acceleration3dIn098mg->y, acceleration3dIn098mg->z);
    MotionDetector_processAcceleration3d(self->motionDetector, acceleration3dIn098mg);
}
