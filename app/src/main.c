#include "../../motion_detector/src/MotionDetector.h"
#include "../../os/src/Interrupts.h"
#include "../../os/src/Os.h"
#include "../../os/src/Task.h"
#include "accelerometer/AccelerometerConfigurator.h"
#include "accelerometer/AccelerometerDriverProvider.h"
#include "accelerometer/AccelerometerSimulatorDriver.h"
#include "accelerometer/RealAccelerometerDriver.h"
#include "accelerometer_data_storage/AccelerometerConfigStorage.h"
#include "button/ButtonDriver.h"

static void runAt10ms(void) {
}

static void runAt20ms(void) {
}

static void runAt50ms(void) {
    AccelerometerDriver_run(AccelerometerDriverProvider_getCurrentAccelerometerDriver());
    MotionDetector_run();
}

static void runAt100ms(void) {
    ButtonDriver_run();
}

void realAccelerometerDataAvailableInt(void) {
    AccelerometerDriver_dataAvailableInt((AccelerometerDriver *)RealAccelerometerDriver_getInstance());
}

void accelerometerSimulatorDataAvailableInt(void) {
    AccelerometerDriver_dataAvailableInt((AccelerometerDriver *)AccelerometerSimulatorDriver_getInstance());
}

void buttonPressInt(void) {
    ButtonDriver_buttonPressInt();
}

int main(void) {
    ButtonDriver_init();
    AccelerometerConfigurator_init(
        AccelerometerConfigStorage_getAccelerometerConfigDao(
            AccelerometerConfigStorage_init(AccelerometerConfigStorage_getInstance())
        )
    );
    RealAccelerometerDriver_init(RealAccelerometerDriver_getInstance());
    AccelerometerSimulatorDriver_init(AccelerometerSimulatorDriver_getInstance());
    AccelerometerDriverProvider_init();
    MotionDetector_init();
    Task tasks[4];
    Task_init(&tasks[0], 10, runAt10ms);
    Task_init(&tasks[1], 20, runAt20ms);
    Task_init(&tasks[2], 50, runAt50ms);
    Task_init(&tasks[3], 100, runAt100ms);
    Os_init(tasks, 4);
    Interrupts_registerRCallback(realAccelerometerDataAvailableInt);
    Interrupts_registerSCallback(accelerometerSimulatorDataAvailableInt);
    Interrupts_registerBCallback(buttonPressInt);
    Os_run();
    return 0;
}
