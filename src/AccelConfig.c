#include "AccelConfig.h"

struct AccelConfig {
    Subject subject;
    bool isSimulatorEnabled;
};

AccelConfig * AccelConfig_getInstance(void) {
    static AccelConfig self;
    return &self;
}

AccelConfig * AccelConfig_init(AccelConfig * const self) {
    *self = (AccelConfig){
        .subject = {
            .observers = { NULL },
            .count = 0 },
        .isSimulatorEnabled = false
    };
    return self;
}

void AccelConfig_toggleAccelDriver(AccelConfig * const self) {
    self->isSimulatorEnabled = !self->isSimulatorEnabled;
    Subject_notifyObservers(&self->subject, &self->isSimulatorEnabled);
}
