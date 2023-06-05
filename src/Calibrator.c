#include "Calibrator.h"

struct Calibrator {
    ButtonDriver * buttonDriver;
    AccConfig * accConfig;
};

Calibrator * Calibrator_getInstance(void) {
    static Calibrator self;
    return &self;
}

void Calibrator_init(Calibrator * const self, ButtonDriver * const buttonDriver, AccConfig * const accConfig) {
    self->buttonDriver = buttonDriver;
    self->accConfig = accConfig;
}

void Calibrator_run(Calibrator * const self) {
    if (ButtonDriver_isPressed(self->buttonDriver)) {
        AccConfig_toggleAccDriver(self->accConfig);
    }
}
