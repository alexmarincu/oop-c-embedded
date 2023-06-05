#ifndef PlatformButtonDriver_h
#define PlatformButtonDriver_h
#include "ButtonDriver.h"

typedef struct PlatformButtonDriver PlatformButtonDriver;

PlatformButtonDriver * PlatformButtonDriver_getInstance(void);
PlatformButtonDriver * PlatformButtonDriver_init(PlatformButtonDriver * const self);

#endif // PlatformButtonDriver_h
