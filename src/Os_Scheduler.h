#ifndef Os_Scheduler_h
#define Os_Scheduler_h

typedef struct Os_Scheduler Os_Scheduler;

Os_Scheduler * Os_Scheduler_getInstance(void);
Os_Scheduler * Os_Scheduler_init(Os_Scheduler * const self);
void Os_Scheduler_run(Os_Scheduler * const self);

#endif // Os_Scheduler_h
