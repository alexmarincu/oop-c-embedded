#include "InterruptHandler.h"
#include "coniow.h"

typedef struct InterruptHandler InterruptHandler;
struct InterruptHandler {
    InterruptHandler_callbackFun realAccelerometerDataAvailableInt;
    InterruptHandler_callbackFun accelerometerSimulatorDataAvailableInt;
    InterruptHandler_callbackFun buttonPressInt;
};

static InterruptHandler self = {
    .realAccelerometerDataAvailableInt = NULL,
    .accelerometerSimulatorDataAvailableInt = NULL,
    .buttonPressInt = NULL
};

static void InterruptHandler_callInt(InterruptHandler_callbackFun callback) {
    if (callback) {
        callback();
    }
}

void InterruptHandler_registerRealAccelerometerDataAvailableIntCallback(InterruptHandler_callbackFun const callback) {
    self.realAccelerometerDataAvailableInt = callback;
}

void InterruptHandler_registerAccelerometerSimulatorDataAvailableIntCallback(InterruptHandler_callbackFun const callback) {
    self.accelerometerSimulatorDataAvailableInt = callback;
}

void InterruptHandler_registerButtonPressIntCallback(InterruptHandler_callbackFun const callback) {
    self.buttonPressInt = callback;
}

void InterruptHandler_run(void) {
    if (_kbhit()) {
        int key = _getch();
        switch (key) {
            case 'r':
            case 'R': {
                InterruptHandler_callInt(self.realAccelerometerDataAvailableInt);
            } break;
            case 's':
            case 'S': {
                InterruptHandler_callInt(self.accelerometerSimulatorDataAvailableInt);
            } break;
            case 'b':
            case 'B': {
                InterruptHandler_callInt(self.buttonPressInt);
            } break;
            default: {
            } break;
        }
    }
}