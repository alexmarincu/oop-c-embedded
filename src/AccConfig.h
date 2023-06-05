#ifndef AccConfig_h
#define AccConfig_h
#include "Subject.h"
#include <stdbool.h>

typedef struct AccConfig AccConfig;

void AccConfig_toggleAccDriver(AccConfig * const self);
AccConfig * AccConfig_getInstance(void);
AccConfig * AccConfig_init(AccConfig * const self);
bool AccConfig_isSimulatorEnabled(AccConfig const * const self);

#endif // AccConfig_h
