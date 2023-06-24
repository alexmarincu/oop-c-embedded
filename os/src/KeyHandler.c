#include "KeyHandler.h"
#include "Interrupts.h"
#include "Os.h"
#include "coniow.h"

static void KeyHandler_onRKeyPress(void) {
    Interrupts_r();
}

static void KeyHandler_onSKeyPress(void) {
    Interrupts_s();
}

static void KeyHandler_onBKeyPress(void) {
    Interrupts_b();
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
            case 'b':
            case 'B': {
                KeyHandler_onBKeyPress();
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
