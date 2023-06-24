#include "AccelerometerConfigurator.h"

typedef struct AccelerometerConfigurator AccelerometerConfigurator;
struct AccelerometerConfigurator {
    AccelerometerConfigDao * accelerometerConfigDao;
};

static AccelerometerConfigurator self;

void AccelerometerConfigurator_init(AccelerometerConfigDao * const accelerometerConfigDao) {
    self.accelerometerConfigDao = accelerometerConfigDao;
}

void AccelerometerConfigurator_toggleAccelerometerDriver(void) {
    AccelerometerConfig * accelerometerConfig = AccelerometerConfigDao_read(self.accelerometerConfigDao, &(AccelerometerConfig){ 0 });
    accelerometerConfig->isSimulatorEnabled = !accelerometerConfig->isSimulatorEnabled;
    AccelerometerConfigDao_write(self.accelerometerConfigDao, accelerometerConfig);
}
