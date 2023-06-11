#ifndef ButtonCtrl_h
#define ButtonCtrl_h
#include "../acc_configurator/AccConfigurator.h"

typedef struct ButtonCtrl ButtonCtrl;

ButtonCtrl * ButtonCtrl_getInstance(void);
ButtonCtrl * ButtonCtrl_init(ButtonCtrl * const self, AccConfigurator * const accConfigurator);
void ButtonCtrl_onButtonPress(ButtonCtrl * const self);

#endif // ButtonCtrl_h
