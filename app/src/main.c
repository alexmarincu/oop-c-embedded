#include "../../hal/src/InterruptHandler.h"
#include "../../motion_detector/src/MotionDetector.h"
#include "../../os/src/Os.h"
#include "../../os/src/Scheduler.h"
#include "../../os/src/Task.h"
#include "../../push_button/src/PushButtonCtrl.h"
#include "../../push_button/src/PushButtonDriver.h"
#include "accelerometer/AccelerometerConfigurator.h"
#include "accelerometer/AccelerometerDriverProvider.h"
#include "accelerometer/AccelerometerSimulatorDriver.h"
#include "accelerometer/RealAccelerometerDriver.h"
#include "accelerometer_data_storage/AccelerometerConfigStorage.h"

static void taskAt10ms(void) {
    // for demo purposes we simulate the interrupts
    InterruptHandler_main();
}

static void taskAt50ms(void) {
    AccelerometerDriver_main(AccelerometerDriverProvider_getCurrentAccelerometerDriver());
    MotionDetector_main();
}

static void taskAt100ms(void) {
    PushButtonDriver_main();
}

void realAccelerometerDataAvailableInt(void) {
    AccelerometerDriver_dataAvailableInt((AccelerometerDriver *)RealAccelerometerDriver_getInstance());
}

void accelerometerSimulatorDataAvailableInt(void) {
    AccelerometerDriver_dataAvailableInt((AccelerometerDriver *)AccelerometerSimulatorDriver_getInstance());
}

void pushButtonPressInt(void) {
    PushButtonDriver_pressInt();
}

void onPushButtonPress() {
    AccelerometerConfigurator_toggleAccelerometerDriver();
}

int main(void) {
    AccelerometerConfigurator_init(
        AccelerometerConfigStorage_getAccelerometerConfigDao(
            AccelerometerConfigStorage_init(AccelerometerConfigStorage_getInstance())
        )
    );
    RealAccelerometerDriver_init(RealAccelerometerDriver_getInstance());
    AccelerometerSimulatorDriver_init(AccelerometerSimulatorDriver_getInstance());
    AccelerometerDriverProvider_init();
    MotionDetector_init();
    Task tasks[3];
    Task_init(&tasks[0], 10, taskAt10ms);
    Task_init(&tasks[1], 50, taskAt50ms);
    Task_init(&tasks[2], 100, taskAt100ms);
    Scheduler_setTasks(tasks, 3);
    InterruptHandler_registerRealAccelerometerDataAvailableIntCbk(realAccelerometerDataAvailableInt);
    InterruptHandler_registerAccelerometerSimulatorDataAvailableIntCbk(accelerometerSimulatorDataAvailableInt);
    InterruptHandler_registerPushButtonPressIntCbk(pushButtonPressInt);
    PushButtonCtrl_registerOnPress(onPushButtonPress);
    Os_main();
    return 0;
}
