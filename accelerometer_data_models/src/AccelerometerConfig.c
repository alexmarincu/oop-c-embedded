#include "AccelerometerConfig.h"

bool AccelerometerConfig_isEqual(AccelerometerConfig * const self, AccelerometerConfig * const other) {
    return self->isSimulatorEnabled == other->isSimulatorEnabled;
}
