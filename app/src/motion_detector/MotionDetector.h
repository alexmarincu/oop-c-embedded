#ifndef MotionDetector_h
#define MotionDetector_h
#include "../../../accelerometer_data_models/src/Acceleration3d.h"

typedef struct MotionDetector MotionDetector;

MotionDetector * MotionDetector_getInstance(void);
MotionDetector * MotionDetector_init(MotionDetector * const self);
void MotionDetector_processAcceleration3d(MotionDetector * const self, Acceleration3d * const acceleration3dIn098mg);
void MotionDetector_run(MotionDetector * const self);

#endif // MotionDetector_h
