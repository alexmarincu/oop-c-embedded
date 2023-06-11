#ifndef ActualAccSimDriver_h
#define ActualAccSimDriver_h
#include "../acc_ctrl/AccCtrl.h"

typedef struct ActualAccSimDriver ActualAccSimDriver;

ActualAccSimDriver * ActualAccSimDriver_getInstance(void);
ActualAccSimDriver * ActualAccSimDriver_init(ActualAccSimDriver * const self, AccCtrl * const accCtrl);
void ActualAccSimDriver_run(ActualAccSimDriver * const self);

#endif // ActualAccSimDriver_h
