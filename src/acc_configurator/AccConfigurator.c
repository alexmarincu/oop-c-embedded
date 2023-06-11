#include "AccConfigurator.h"

struct AccConfigurator {
    AccConfigDao * accConfigDao;
};

AccConfigurator * AccConfigurator_getInstance(void) {
    static AccConfigurator self;
    return &self;
}

AccConfigurator * AccConfigurator_init(AccConfigurator * const self, AccConfigDao * const accConfigDao) {
    self->accConfigDao = accConfigDao;
    return self;
}

void AccConfigurator_toggleAccDriver(AccConfigurator * const self) {
    AccConfig * accConfig = AccConfigDao_read(self->accConfigDao, &(AccConfig){});
    accConfig->isSimulatorEnabled = !accConfig->isSimulatorEnabled;
    AccConfigDao_write(self->accConfigDao, accConfig);
}
