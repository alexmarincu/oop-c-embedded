#include "DefaultButtonDriver.h"

struct DefaultButtonDriver {
    ButtonDriver buttonDriver;
};

DefaultButtonDriver * DefaultButtonDriver_getInstance(void) {
    static DefaultButtonDriver self;
    return &self;
}

DefaultButtonDriver * DefaultButtonDriver_init(DefaultButtonDriver * const self) {
    ButtonDriver_init((ButtonDriver *)self);
    return self;
}
