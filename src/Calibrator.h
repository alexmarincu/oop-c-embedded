#ifndef Calibrator_h
#define Calibrator_h
#include "AccConfig.h"
#include "ButtonDriver.h"

typedef struct Calibrator Calibrator;

Calibrator * Calibrator_getInstance(void);
void Calibrator_init(Calibrator * const self, ButtonDriver * const buttonDriver, AccConfig * const accConfig);
void Calibrator_run(Calibrator * const self);

#endif // Calibrator_h
