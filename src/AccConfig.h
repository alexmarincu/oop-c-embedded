#ifndef AccConfig_h
#define AccConfig_h
#include "Subject.h"

typedef struct AccConfig AccConfig;

void AccConfig_toggleAccDriver(AccConfig * const self);
AccConfig * AccConfig_getInstance(void);
AccConfig * AccConfig_init(AccConfig * const self);

#endif // AccConfig_h
