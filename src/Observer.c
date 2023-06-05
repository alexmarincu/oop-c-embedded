#include "Observer.h"

Observer * Observer_init(Observer * const self, Observer_onUpdateFun const onUpdate) {
    self->onUpdate = onUpdate;
    return self;
}
