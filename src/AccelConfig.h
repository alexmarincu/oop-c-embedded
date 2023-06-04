#ifndef AccelConfig_h
#define AccelConfig_h
#include "Subject.h"

typedef struct AccelConfig AccelConfig;

void AccelConfig_toggleAccelDriver(AccelConfig * const self);
AccelConfig * AccelConfig_getInstance(void);
AccelConfig * AccelConfig_init(AccelConfig * const self);

#endif // AccelConfig_h
