#include "AccelerometerConfigStorage.h"
#include "../../../lib/src/observer/Subject.h"
#include <string.h>

#define AccelerometerConfigStorage_observersMaxCount 1u

struct AccelerometerConfigStorage {
    Subject subject;
    Observer * observers[AccelerometerConfigStorage_observersMaxCount];
    AccelerometerConfigDao accelerometerConfigDao;
    AccelerometerConfig accelerometerConfig;
};

AccelerometerConfigStorage * AccelerometerConfigStorage_getInstance(void) {
    static AccelerometerConfigStorage self;
    return &self;
}

AccelerometerConfigStorage * AccelerometerConfigStorage_init(AccelerometerConfigStorage * const self) {
    Subject_init((Subject *)self, self->observers, AccelerometerConfigStorage_observersMaxCount);
    memset(self->observers, 0, sizeof(self->observers));
    AccelerometerConfigDao_init(
        &self->accelerometerConfigDao,
        self,
        (AccelerometerConfigDao_writeFun)AccelerometerConfigStorage_write,
        (AccelerometerConfigDao_readFun)AccelerometerConfigStorage_read
    );
    self->accelerometerConfig = (AccelerometerConfig){ .isSimulatorEnabled = false };
    return self;
}

AccelerometerConfigDao * AccelerometerConfigStorage_getAccelerometerConfigDao(AccelerometerConfigStorage * const self) {
    return &self->accelerometerConfigDao;
}

void AccelerometerConfigStorage_write(AccelerometerConfigStorage * const self, AccelerometerConfig * const accelerometerConfig) {
    AccelerometerConfig old = self->accelerometerConfig;
    self->accelerometerConfig = *accelerometerConfig;
    if (!AccelerometerConfig_isEqual(&old, &self->accelerometerConfig)) {
        Subject_notifyObservers(&self->subject);
    }
}

AccelerometerConfig * AccelerometerConfigStorage_read(
    AccelerometerConfigStorage * const self, AccelerometerConfig * const accelerometerConfig
) {
    *accelerometerConfig = self->accelerometerConfig;
    return accelerometerConfig;
}
