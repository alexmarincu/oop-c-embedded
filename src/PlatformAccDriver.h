#ifndef PlatformAccDriver_h
#define PlatformAccDriver_h
#include "AccDriver.h"

typedef struct PlatformAccDriver PlatformAccDriver;

PlatformAccDriver * PlatformAccDriver_init(PlatformAccDriver * const self);
PlatformAccDriver * PlatformAccDriver_getInstance(void);

#endif // PlatformAccDriver_h
