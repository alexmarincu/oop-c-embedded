#ifndef AccelerometerConfig_h
#define AccelerometerConfig_h
#include <stdbool.h>

typedef struct AccelerometerConfig AccelerometerConfig;
struct AccelerometerConfig {
    bool isSimulatorEnabled;
};

bool AccelerometerConfig_isEqual(AccelerometerConfig * const self, AccelerometerConfig * const other);

#endif // AccelerometerConfig_h
