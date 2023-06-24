#include "ButtonCtrl.h"
#include "../accelerometer/AccelerometerConfigurator.h"

void ButtonCtrl_onButtonPress(void) {
    AccelerometerConfigurator_toggleAccelerometerDriver();
}
