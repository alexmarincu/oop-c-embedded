#ifndef AccCtrl_h
#define AccCtrl_h
#include "AccDriver.h"

typedef struct AccCtrl AccCtrl;

AccCtrl * AccCtrl_getInstance(void);
void AccCtrl_init(AccCtrl * const self, AccDriver * const accDriver);
void AccCtrl_setAccDriver(AccCtrl * const self, AccDriver * const accDriver);
void AccCtrl_run(AccCtrl * const self);

#endif // AccCtrl_h
