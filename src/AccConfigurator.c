#include "AccConfigurator.h"

struct AccConfigurator {
    ButtonDriver * buttonDriver;
    AccConfig * accConfig;
};

AccConfigurator * AccConfigurator_getInstance(void) {
    static AccConfigurator self;
    return &self;
}

void AccConfigurator_init(AccConfigurator * const self, ButtonDriver * const buttonDriver, AccConfig * const accConfig) {
    self->buttonDriver = buttonDriver;
    self->accConfig = accConfig;
}

void AccConfigurator_run(AccConfigurator * const self) {
    if (ButtonDriver_isPressed(self->buttonDriver)) {
        AccConfig_toggleAccDriver(self->accConfig);
    }
}
