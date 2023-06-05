#ifndef Os_Task_h
#define Os_Task_h
#include "Os_Time.h"
#include <stdint.h>

typedef struct Os_Task Os_Task;
typedef struct Os_TaskClass Os_TaskClass;
typedef void (*Os_Task_operationFun)(void * const self);
struct Os_Task {
    Os_TaskClass * klass;
    uint32_t startTimeAtLastRunIn1ms;
    uint32_t maxRunDurationIn1ms;
    uint32_t repetitionRateIn1ms;
    void * client;
    Os_Task_operationFun operation;
};

Os_TaskClass * Os_TaskClass_getInstance(void);
Os_TaskClass * Os_TaskClass_init(Os_TaskClass * const self);
Os_Task * Os_Task_init(
    Os_Task * const self,
    uint32_t const repetitionRateIn1ms, void * const client, Os_Task_operationFun const operation
);
void Os_Task_run(Os_Task * const self);

#endif // Os_Task_h
