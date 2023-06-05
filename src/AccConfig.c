#include "AccConfig.h"
#include <stdbool.h>
#include <string.h>

#define AccConfig_observersMaxCount 1

struct AccConfig {
    Subject subject;
    Observer * observers[AccConfig_observersMaxCount];
    bool isSimulatorEnabled;
};

AccConfig * AccConfig_getInstance(void) {
    static AccConfig self;
    return &self;
}

AccConfig * AccConfig_init(AccConfig * const self) {
    Subject_init((Subject *)self, self->observers, 1);
    memset(self->observers, 0, sizeof(self->observers));
    self->isSimulatorEnabled = false;
    return self;
}

void AccConfig_toggleAccDriver(AccConfig * const self) {
    self->isSimulatorEnabled = !self->isSimulatorEnabled;
    Subject_notifyObservers(&self->subject, &self->isSimulatorEnabled);
}
