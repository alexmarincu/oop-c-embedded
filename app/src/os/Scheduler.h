#ifndef Scheduler_h
#define Scheduler_h

typedef struct Scheduler Scheduler;

Scheduler * Scheduler_getInstance(void);
Scheduler * Scheduler_init(Scheduler * const self);
void Scheduler_run(Scheduler * const self);

#endif // Scheduler_h
