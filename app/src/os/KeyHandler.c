#include "KeyHandler.h"
#include "Interrupts.h"
#include "Os.h"
#include "conioWrapper.h"

void KeyHandler_init(void) {
}

static void KeyHandler_onRKeyPress(void) {
    Interrupts_realAccelerometerDataAvailable();
}

static void KeyHandler_onSKeyPress(void) {
    Interrupts_accelerometerSimulatorDataAvailable();
}

static void KeyHandler_onTKeyPress(void) {
    Interrupts_buttonPress();
}

static void KeyHandler_onQKeyPress(void) {
    Os_quit();
}

void KeyHandler_run(void) {
    if (_kbhit()) {
        int key = _getch();
        switch (key) {
            case 'r':
            case 'R': {
                KeyHandler_onRKeyPress();
            } break;
            case 's':
            case 'S': {
                KeyHandler_onSKeyPress();
            } break;
            case 't':
            case 'T': {
                KeyHandler_onTKeyPress();
            } break;
            case 'q':
            case 'Q': {
                KeyHandler_onQKeyPress();
            } break;
            default: {
            } break;
        }
    }
}
