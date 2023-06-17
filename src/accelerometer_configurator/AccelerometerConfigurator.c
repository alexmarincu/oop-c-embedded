#include "AccelerometerConfigurator.h"

struct AccelerometerConfigurator {
    AccelerometerConfigDao * accelerometerConfigDao;
};

AccelerometerConfigurator * AccelerometerConfigurator_getInstance(void) {
    static AccelerometerConfigurator self;
    return &self;
}

AccelerometerConfigurator * AccelerometerConfigurator_init(
    AccelerometerConfigurator * const self, AccelerometerConfigDao * const accelerometerConfigDao
) {
    self->accelerometerConfigDao = accelerometerConfigDao;
    return self;
}

void AccelerometerConfigurator_toggleAccelerometerDriver(AccelerometerConfigurator * const self) {
    AccelerometerConfig * accelerometerConfig = AccelerometerConfigDao_read(self->accelerometerConfigDao, &(AccelerometerConfig){ 0 });
    accelerometerConfig->isSimulatorEnabled = !accelerometerConfig->isSimulatorEnabled;
    AccelerometerConfigDao_write(self->accelerometerConfigDao, accelerometerConfig);
}
