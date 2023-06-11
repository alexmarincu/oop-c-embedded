#ifndef ActualAccDriver_h
#define ActualAccDriver_h
#include "../acc_ctrl/AccCtrl.h"

typedef struct ActualAccDriver ActualAccDriver;

ActualAccDriver * ActualAccDriver_getInstance(void);
ActualAccDriver * ActualAccDriver_init(ActualAccDriver * const self, AccCtrl * const accCtrl);
void ActualAccDriver_run(ActualAccDriver * const self);

#endif // ActualAccDriver_h
