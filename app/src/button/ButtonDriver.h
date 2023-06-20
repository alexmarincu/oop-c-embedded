#ifndef ButtonDriver_h
#define ButtonDriver_h
#include "ButtonCtrl.h"

typedef struct ButtonDriver ButtonDriver;

ButtonDriver * ButtonDriver_getInstance(void);
ButtonDriver * ButtonDriver_init(ButtonDriver * const self, ButtonCtrl * const buttonCtrl);
void ButtonDriver_run(ButtonDriver * const self);
void ButtonDriver_buttonPressInt(ButtonDriver * const self);

#endif // ButtonDriver_h
