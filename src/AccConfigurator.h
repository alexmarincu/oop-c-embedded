#ifndef AccConfigurator_h
#define AccConfigurator_h
#include "AccConfig.h"
#include "ButtonDriver.h"

typedef struct AccConfigurator AccConfigurator;

AccConfigurator * AccConfigurator_getInstance(void);
void AccConfigurator_init(AccConfigurator * const self, ButtonDriver * const buttonDriver, AccConfig * const accConfig);
void AccConfigurator_run(AccConfigurator * const self);

#endif // AccConfigurator_H
