#ifndef Timer_h
#define Timer_h
#include <stdbool.h>
#include <stdint.h>

typedef struct Timer Timer;
struct Timer {
    uint32_t startTimeIn1ms;
    uint32_t durationIn1ms;
    bool isRunning;
};

Timer * Timer_init(Timer * const self);
void Timer_start(Timer * const self, uint32_t const durationIn1ms);
void Timer_stop(Timer * const self);
bool Timer_isRunning(Timer * const self);
bool Timer_isExpired(Timer * const self);

#endif // Timer_h
