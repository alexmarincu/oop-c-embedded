#ifndef os_Scheduler_h
#define os_Scheduler_h

typedef struct os_Scheduler os_Scheduler;

os_Scheduler * os_Scheduler_getInstance(void);
os_Scheduler * os_Scheduler_init(os_Scheduler * const self);
void os_Scheduler_run(os_Scheduler * const self);

#endif // os_Scheduler_h
