#include "AccelerometerDriverProvider.h"
#include "../../../accelerometer_data_models/src/AccelerometerConfig.h"
#include "../../../utils/src/observer/Observer.h"
#include "../../../utils/src/observer/Subject.h"
#include "../accelerometer_data_storage/AccelerometerConfigStorage.h"
#include "AccelerometerSimulatorDriver.h"
#include "RealAccelerometerDriver.h"
#include <stdio.h>

typedef struct AccelerometerDriverProvider AccelerometerDriverProvider;
struct AccelerometerDriverProvider {
    Observer observer;
    AccelerometerDriver * currentAccelerometerDriver;
};

static void AccelerometerDriverProvider_onConfigChange(void);

static AccelerometerDriverProvider self;

void AccelerometerDriverProvider_init(void) {
    Observer_init((Observer *)&self, &self, (Observer_onUpdateFun)AccelerometerDriverProvider_onConfigChange);
    self.currentAccelerometerDriver = (AccelerometerDriver *)RealAccelerometerDriver_getInstance();
    Subject_registerObserver((Subject *)AccelerometerConfigStorage_getInstance(), (Observer *)&self);
}

static void AccelerometerDriverProvider_onConfigChange(void) {
    AccelerometerConfig * accelerometerConfig =
        AccelerometerConfigStorage_read(AccelerometerConfigStorage_getInstance(), &(AccelerometerConfig){ 0 });
    if (accelerometerConfig->isSimulatorEnabled) {
        self.currentAccelerometerDriver = (AccelerometerDriver *)AccelerometerSimulatorDriver_getInstance();
        printf("Switch to acc sim\n");
    } else {
        self.currentAccelerometerDriver = (AccelerometerDriver *)RealAccelerometerDriver_getInstance();
        printf("Switch to acc\n");
    }
}

AccelerometerDriver * AccelerometerDriverProvider_getCurrentAccelerometerDriver(void) {
    return self.currentAccelerometerDriver;
}
