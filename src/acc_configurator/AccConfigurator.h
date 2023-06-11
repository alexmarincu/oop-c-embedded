#ifndef AccConfigurator_h
#define AccConfigurator_h
#include "../acc_config/AccConfigDao.h"

typedef struct AccConfigurator AccConfigurator;

AccConfigurator * AccConfigurator_getInstance(void);
AccConfigurator * AccConfigurator_init(AccConfigurator * const self, AccConfigDao * const accConfigDao);
void AccConfigurator_toggleAccDriver(AccConfigurator * const self);

#endif // AccConfigurator_H
