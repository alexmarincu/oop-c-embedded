#include "os_KeyHandler.h"
#include "Os.h"
#include "conioWrapper.h"
#include "os_Interrupts.h"

struct os_KeyHandler {
    Os * os;
};

os_KeyHandler * os_KeyHandler_getInstance(void) {
    static os_KeyHandler self;
    return &self;
}

os_KeyHandler * os_KeyHandler_init(os_KeyHandler * const self) {
    self->os = Os_getInstance();
    return self;
}

static void os_KeyHandler_onRKeyPress(os_KeyHandler * const self) {
    (void)self;
    os_Interrupts_accDataAvailable();
}

static void os_KeyHandler_onSKeyPress(os_KeyHandler * const self) {
    (void)self;
    os_Interrupts_simAccelerometerDataAvailable();
}

static void os_KeyHandler_onTKeyPress(os_KeyHandler * const self) {
    (void)self;
    os_Interrupts_buttonPress();
}

static void os_KeyHandler_onQKeyPress(os_KeyHandler * const self) {
    Os_quit(self->os);
}

void os_KeyHandler_run(os_KeyHandler * const self) {
    if (_kbhit()) {
        int key = _getch();
        switch (key) {
            case 'r':
            case 'R': {
                os_KeyHandler_onRKeyPress(self);
            } break;
            case 's':
            case 'S': {
                os_KeyHandler_onSKeyPress(self);
            } break;
            case 't':
            case 'T': {
                os_KeyHandler_onTKeyPress(self);
            } break;
            case 'q':
            case 'Q': {
                os_KeyHandler_onQKeyPress(self);
            } break;
            default: {
            } break;
        }
    }
}
