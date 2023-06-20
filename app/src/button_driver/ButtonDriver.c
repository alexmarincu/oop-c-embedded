#include "ButtonDriver.h"
#include <stdbool.h>

struct ButtonDriver {
    ButtonCtrl * buttonCtrl;
    bool volatile isPressed;
};

ButtonDriver * ButtonDriver_getInstance(void) {
    static ButtonDriver self;
    return &self;
}

ButtonDriver * ButtonDriver_init(ButtonDriver * const self, ButtonCtrl * const buttonCtrl) {
    self->buttonCtrl = buttonCtrl;
    self->isPressed = false;
    return self;
}

void ButtonDriver_buttonPressInt(ButtonDriver * const self) {
    self->isPressed = true;
}

void ButtonDriver_run(ButtonDriver * const self) {
    if (self->isPressed) {
        self->isPressed = false;
        ButtonCtrl_onButtonPress(self->buttonCtrl);
    }
}