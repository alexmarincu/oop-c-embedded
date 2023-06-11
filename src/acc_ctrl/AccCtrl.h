#ifndef AccCtrl_h
#define AccCtrl_h
#include "../acceleration/Acceleration3d.h"
#include "../motion_detector/MotionDetector.h"

typedef struct AccCtrl AccCtrl;

AccCtrl * AccCtrl_getInstance(void);
AccCtrl * AccCtrl_init(AccCtrl * const self, MotionDetector * const motionDetector);
void AccCtrl_onDataReceived(AccCtrl * const self, Acceleration3d * const acceleration3dIn098mg);

#endif // AccCtrl_h
