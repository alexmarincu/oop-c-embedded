#ifndef PlatformAccSimDriver_h
#define PlatformAccSimDriver_h
#include "AccDriver.h"

typedef struct PlatformAccSimDriver PlatformAccSimDriver;

PlatformAccSimDriver * PlatformAccSimDriver_init(PlatformAccSimDriver * const self);
PlatformAccSimDriver * PlatformAccSimDriver_getInstance(void);

#endif // PlatformAccSimDriver_h
