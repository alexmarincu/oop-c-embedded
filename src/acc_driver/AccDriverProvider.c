#include "AccDriverProvider.h"
#include "../acc_config/AccConfig.h"
#include "../acc_config_storage/AccConfigStorage.h"
#include "../lib/observer/Observer.h"
#include "../lib/observer/Subject.h"
#include "ActualAccDriver.h"
#include "ActualAccSimDriver.h"
#include <stdio.h>

struct AccDriverProvider {
    Observer observer;
    AccConfigStorage * accConfigStorage;
    ActualAccDriver * actualAccDriver;
    ActualAccSimDriver * actualAccSimDriver;
    AccDriver * currentAccDriver;
};

static void AccDriverProvider_onConfigChange(AccDriverProvider * const self);

AccDriverProvider * AccDriverProvider_getInstance(void) {
    static AccDriverProvider self;
    return &self;
}

AccDriverProvider * AccDriverProvider_init(AccDriverProvider * const self) {
    Observer_init((Observer *)self, self, (Observer_onUpdateFun)AccDriverProvider_onConfigChange);
    self->actualAccDriver = ActualAccDriver_init(
        ActualAccDriver_getInstance(),
        AccCtrl_init(
            AccCtrl_getInstance(),
            MotionDetector_init(MotionDetector_getInstance())
        )
    );
    self->actualAccSimDriver = ActualAccSimDriver_init(
        ActualAccSimDriver_getInstance(),
        AccCtrl_init(
            AccCtrl_getInstance(),
            MotionDetector_init(MotionDetector_getInstance())
        )
    );
    self->accConfigStorage = AccConfigStorage_getInstance();
    self->currentAccDriver = (AccDriver *)self->actualAccDriver;
    Subject_registerObserver((Subject *)self->accConfigStorage, (Observer *)self);
    return self;
}

static void AccDriverProvider_onConfigChange(AccDriverProvider * const self) {
    AccConfig * accConfig = AccConfigStorage_read(self->accConfigStorage, &(AccConfig){});
    if (accConfig->isSimulatorEnabled) {
        self->currentAccDriver = (AccDriver *)self->actualAccSimDriver;
        printf("Switch to acc sim\n");
    } else {
        self->currentAccDriver = (AccDriver *)self->actualAccDriver;
        printf("Switch to acc\n");
    }
}

AccDriver * AccDriverProvider_getCurrentAccDriver(AccDriverProvider * const self) {
    return self->currentAccDriver;
}
