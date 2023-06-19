#include "Subject.h"

Subject * Subject_init(Subject * const self, Observer ** const observers, uint32_t const observersMaxCount) {
    self->observers = observers;
    self->observersCount = 0;
    self->observersMaxCount = observersMaxCount;
    return self;
}

void Subject_registerObserver(Subject * const self, Observer * const observer) {
    if (self->observersCount < self->observersMaxCount) {
        self->observers[self->observersCount++] = observer;
    }
}

void Subject_notifyObservers(Subject * const self) {
    for (uint32_t i = 0; i < self->observersCount; ++i) {
        Observer * observer = self->observers[i];
        Observer_onUpdate(observer);
    }
}