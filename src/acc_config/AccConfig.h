#ifndef AccConfig_h
#define AccConfig_h
#include <stdbool.h>

typedef struct AccConfig AccConfig;
struct AccConfig {
    bool isSimulatorEnabled;
};

bool AccConfig_isEqual(AccConfig * const self, AccConfig * const other);

#endif // AccConfig_h
