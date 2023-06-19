#ifndef AccelerometerCtrl_h
#define AccelerometerCtrl_h
#include "../../../accelerometer_data_models/src/Acceleration3d.h"
#include "../motion_detector/MotionDetector.h"

typedef struct AccelerometerCtrl AccelerometerCtrl;

AccelerometerCtrl * AccelerometerCtrl_getInstance(void);
AccelerometerCtrl * AccelerometerCtrl_init(AccelerometerCtrl * const self, MotionDetector * const motionDetector);
void AccelerometerCtrl_onDataReceived(AccelerometerCtrl * const self, Acceleration3d * const acceleration3dIn098mg);

#endif // AccelerometerCtrl_h
