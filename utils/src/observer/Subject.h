#ifndef Subject_h
#define Subject_h
#include "Observer.h"
#include <stdint.h>

typedef struct Subject Subject;

struct Subject {
    Observer ** observers;
    uint32_t observersCount;
    uint32_t observersMaxCount;
};

Subject * Subject_init(Subject * const self, Observer ** const observers, uint32_t const observersMaxCount);
void Subject_registerObserver(Subject * const self, Observer * const observer);
void Subject_notifyObservers(Subject * const self);

#endif // Subject_h
