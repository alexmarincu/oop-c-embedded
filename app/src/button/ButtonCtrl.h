#ifndef ButtonCtrl_h
#define ButtonCtrl_h
#include "../accelerometer/AccelerometerConfigurator.h"

typedef struct ButtonCtrl ButtonCtrl;

ButtonCtrl * ButtonCtrl_getInstance(void);
ButtonCtrl * ButtonCtrl_init(ButtonCtrl * const self, AccelerometerConfigurator * const accelerometerConfigurator);
void ButtonCtrl_onButtonPress(ButtonCtrl * const self);

#endif // ButtonCtrl_h
