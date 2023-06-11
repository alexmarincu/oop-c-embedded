#include "ButtonCtrl.h"

struct ButtonCtrl {
    AccConfigurator * accConfigurator;
};

ButtonCtrl * ButtonCtrl_getInstance(void) {
    static ButtonCtrl self;
    return &self;
}

ButtonCtrl * ButtonCtrl_init(ButtonCtrl * const self, AccConfigurator * const accConfigurator) {
    self->accConfigurator = accConfigurator;
    return self;
}

void ButtonCtrl_onButtonPress(ButtonCtrl * const self) {
    AccConfigurator_toggleAccDriver(self->accConfigurator);
}
