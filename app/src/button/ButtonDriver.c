#include "ButtonDriver.h"
#include "ButtonCtrl.h"
#include <stdbool.h>

typedef struct ButtonDriver ButtonDriver;
struct ButtonDriver {
    bool volatile isPressed;
};

static ButtonDriver self;

void ButtonDriver_init(void) {
    self.isPressed = false;
}

void ButtonDriver_buttonPressInt(void) {
    self.isPressed = true;
}

void ButtonDriver_run(void) {
    if (self.isPressed) {
        self.isPressed = false;
        ButtonCtrl_onButtonPress();
    }
}