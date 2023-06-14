#include "AccConfigStorage.h"
#include "../lib/observer/Subject.h"
#include <string.h>

#define AccConfigStorage_observersMaxCount 1u

struct AccConfigStorage {
    Subject subject;
    Observer * observers[AccConfigStorage_observersMaxCount];
    AccConfigDao accConfigDao;
    AccConfig accConfig;
};

AccConfigStorage * AccConfigStorage_getInstance(void) {
    static AccConfigStorage self;
    return &self;
}

AccConfigStorage * AccConfigStorage_init(AccConfigStorage * const self) {
    Subject_init((Subject *)self, self->observers, AccConfigStorage_observersMaxCount);
    memset(self->observers, 0, sizeof(self->observers));
    AccConfigDao_init(&self->accConfigDao, self, (AccConfigDao_writeFun)AccConfigStorage_write, (AccConfigDao_readFun)AccConfigStorage_read);
    self->accConfig = (AccConfig){ .isSimulatorEnabled = false };
    return self;
}

AccConfigDao * AccConfigStorage_getAccConfigDao(AccConfigStorage * const self) {
    return &self->accConfigDao;
}

void AccConfigStorage_write(AccConfigStorage * const self, AccConfig * const accConfig) {
    AccConfig old = self->accConfig;
    self->accConfig = *accConfig;
    if (!AccConfig_isEqual(&old, &self->accConfig)) {
        Subject_notifyObservers(&self->subject);
    }
}

AccConfig * AccConfigStorage_read(AccConfigStorage * const self, AccConfig * const accConfig) {
    *accConfig = self->accConfig;
    return accConfig;
}
