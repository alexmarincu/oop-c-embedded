#include "AccDriverSwitch.h"
#include "PlatformAccDriver.h"
#include "PlatformAccSimDriver.h"
#include <stdio.h>

struct AccDriverSwitch {
    Observer observer;
    AccCtrl * accCtrl;
    AccConfig * accConfig;
    PlatformAccDriver * platformAccDriver;
    PlatformAccSimDriver * platformAccSimDriver;
};

static void AccDriverSwitch_onConfigChange(AccDriverSwitch * const self);

AccDriverSwitch * AccDriverSwitch_getInstance(void) {
    static AccDriverSwitch self;
    return &self;
}

AccDriverSwitch * AccDriverSwitch_init(AccDriverSwitch * const self) {
    Observer_init((Observer *)self, (Observer_onUpdateFun)AccDriverSwitch_onConfigChange);
    self->accConfig = AccConfig_getInstance();
    self->accCtrl = AccCtrl_getInstance();
    self->platformAccDriver = PlatformAccDriver_getInstance();
    self->platformAccSimDriver = PlatformAccSimDriver_getInstance();
    Subject_registerObserver((Subject *)self->accConfig, (Observer *)self);
    return self;
}

static void AccDriverSwitch_onConfigChange(AccDriverSwitch * const self) {
    if (AccConfig_isSimulatorEnabled(self->accConfig)) {
        AccCtrl_setAccDriver(self->accCtrl, (AccDriver *)self->platformAccSimDriver);
        printf("switch to acc sim\n");
    } else {
        AccCtrl_setAccDriver(self->accCtrl, (AccDriver *)self->platformAccDriver);
        printf("switch to acc\n");
    }
}