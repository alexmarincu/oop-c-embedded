#include "ButtonCtrl.h"

struct ButtonCtrl {
    AccelerometerConfigurator * accelerometerConfigurator;
};

ButtonCtrl * ButtonCtrl_getInstance(void) {
    static ButtonCtrl self;
    return &self;
}

ButtonCtrl * ButtonCtrl_init(ButtonCtrl * const self, AccelerometerConfigurator * const accelerometerConfigurator) {
    self->accelerometerConfigurator = accelerometerConfigurator;
    return self;
}

void ButtonCtrl_onButtonPress(ButtonCtrl * const self) {
    AccelerometerConfigurator_toggleAccelerometerDriver(self->accelerometerConfigurator);
}
