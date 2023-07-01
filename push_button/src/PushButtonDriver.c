#include "PushButtonDriver.h"
#include "PushButtonCtrl.h"
#include <stdbool.h>

typedef struct PushButtonDriver PushButtonDriver;
struct PushButtonDriver {
    bool volatile isPressed;
};

static PushButtonDriver self = {
    .isPressed = false
};

void PushButtonDriver_pressInt(void) {
    self.isPressed = true;
}

void PushButtonDriver_main(void) {
    if (self.isPressed) {
        self.isPressed = false;
        // Perform some processing for debounce
        // When we detect button press call button controller "on press" function
        PushButtonCtrl_onPress();
    }
}