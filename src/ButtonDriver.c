#include "ButtonDriver.h"

ButtonDriver * ButtonDriver_init(ButtonDriver * const self) {
    self->isPressed = false;
    return self;
}

void ButtonDriver_onButtonPressInt(ButtonDriver * const self) {
    self->isPressed = true;
}

bool ButtonDriver_isPressed(ButtonDriver * const self) {
    bool isPressed = self->isPressed;
    self->isPressed = false;
    return isPressed;
}