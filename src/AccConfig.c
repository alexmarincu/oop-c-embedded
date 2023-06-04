#include "AccConfig.h"

struct AccConfig {
    Subject subject;
    bool isSimulatorEnabled;
};

AccConfig * AccConfig_getInstance(void) {
    static AccConfig self;
    return &self;
}

AccConfig * AccConfig_init(AccConfig * const self) {
    *self = (AccConfig){
        .subject = {
            .observers = { 0 },
            .count = 0 },
        .isSimulatorEnabled = false
    };
    return self;
}

void AccConfig_toggleAccDriver(AccConfig * const self) {
    self->isSimulatorEnabled = !self->isSimulatorEnabled;
    Subject_notifyObservers(&self->subject, &self->isSimulatorEnabled);
}
