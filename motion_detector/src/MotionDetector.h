#ifndef MotionDetector_h
#define MotionDetector_h
#include "../../accelerometer_data_models/src/Acceleration3d.h"

typedef struct MotionDetector MotionDetector;

void MotionDetector_init(void);
void MotionDetector_processAcceleration3d(Acceleration3d * const acceleration3dIn098mg);
void MotionDetector_main(void);

#endif // MotionDetector_h
