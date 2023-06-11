#ifndef AccDriverProvider_h
#define AccDriverProvider_h
#include "AccDriver.h"

typedef struct AccDriverProvider AccDriverProvider;

AccDriverProvider * AccDriverProvider_getInstance(void);
AccDriverProvider * AccDriverProvider_init(AccDriverProvider * const self);
AccDriver * AccDriverProvider_getCurrentAccDriver(AccDriverProvider * const self);

#endif // AccDriverProvider_h
