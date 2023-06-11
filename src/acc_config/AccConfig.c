#include "AccConfig.h"

bool AccConfig_isEqual(AccConfig * const self, AccConfig * const other) {
    return self->isSimulatorEnabled == other->isSimulatorEnabled;
}
