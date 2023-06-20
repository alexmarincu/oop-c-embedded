#include "Interrupts.h"
#include "../accelerometer/AccelerometerDriver.h"
#include "../accelerometer/AccelerometerSimulatorDriver.h"
#include "../accelerometer/RealAccelerometerDriver.h"
#include "../button/ButtonDriver.h"

void Interrupts_realAccelerometerDataAvailable(void) {
    AccelerometerDriver_dataAvailableInt((AccelerometerDriver *)RealAccelerometerDriver_getInstance());
}

void Interrupts_accelerometerSimulatorDataAvailable(void) {
    AccelerometerDriver_dataAvailableInt((AccelerometerDriver *)AccelerometerSimulatorDriver_getInstance());
}

void Interrupts_buttonPress(void) {
    ButtonDriver_buttonPressInt(ButtonDriver_getInstance());
}
