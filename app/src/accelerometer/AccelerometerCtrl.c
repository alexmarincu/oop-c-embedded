#include "AccelerometerCtrl.h"
#include "../../../motion_detector/src/MotionDetector.h"
#include <stdio.h>

void AccelerometerCtrl_onDataReceived(Acceleration3d * const acceleration3dIn098mg) {
    printf("x = %d, y = %d, z = %d\n", acceleration3dIn098mg->x, acceleration3dIn098mg->y, acceleration3dIn098mg->z);
    MotionDetector_processAcceleration3d(acceleration3dIn098mg);
}
