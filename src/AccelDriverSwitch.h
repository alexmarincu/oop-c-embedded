#ifndef AccelDriverSwitch_h
#define AccelDriverSwitch_h
#include "AccelConfig.h"
#include "AccelCtrl.h"
#include "Observer.h"

typedef struct AccelDriverSwitch AccelDriverSwitch;

AccelDriverSwitch * AccelDriverSwitch_getInstance(void);
AccelDriverSwitch * AccelDriverSwitch_init(AccelDriverSwitch * const self);
void AccelDriverSwitch_toggleAccelDriver(void);

#endif // AccelDriverSwitch_h
