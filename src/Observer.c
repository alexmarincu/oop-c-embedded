#include "Observer.h"

Observer * Observer_init(Observer * const self, Observer_updateFun const update) {
    self->update = update;
    return self;
}
