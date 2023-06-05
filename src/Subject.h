#ifndef Subject_h
#define Subject_h
#include "Observer.h"
#include <stdint.h>

typedef struct Subject Subject;

struct Subject {
    Observer ** observers;
    uint32_t count;
    uint32_t maxCount;
};

Subject * Subject_init(Subject * const self, Observer ** const observers, uint32_t const maxCount);
void Subject_registerObserver(Subject * self, Observer * observer);
void Subject_notifyObservers(Subject * self);

#endif // Subject_h
