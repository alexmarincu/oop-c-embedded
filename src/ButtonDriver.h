#ifndef ButtonDriver_h
#define ButtonDriver_h
#include <stdbool.h>

typedef struct ButtonDriver ButtonDriver;

struct ButtonDriver {
    bool isPressed;
};

ButtonDriver * ButtonDriver_init(ButtonDriver * const self);
bool ButtonDriver_isPressed(ButtonDriver * const self);
void ButtonDriver_onButtonPressInt(ButtonDriver * const self);

#endif // ButtonDriver_h
