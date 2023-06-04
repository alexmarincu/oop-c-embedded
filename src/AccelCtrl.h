#ifndef AccelCtrl_h
#define AccelCtrl_h
#include "AccelDriver.h"
#include "Observer.h"

typedef struct AccelCtrl AccelCtrl;

AccelCtrl * AccelCtrl_getInstance(void);
void AccelCtrl_init(AccelCtrl * const self, AccelDriver * const accelDriver);
void AccelCtrl_setAccelDriver(AccelCtrl * const self, AccelDriver * const accelDriver);
void AccelCtrl_main(AccelCtrl * const self);

#endif // AccelCtrl_h
