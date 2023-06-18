#ifndef os_Task_h
#define os_Task_h
#include <stdint.h>

typedef struct os_Task os_Task;
typedef void (*os_Task_operationFun)(void * const self);
struct os_Task {
    uint32_t startTimeAtLastRunIn1ms;
    uint32_t maxRunDurationIn1ms;
    uint32_t repetitionRateIn1ms;
    void * client;
    os_Task_operationFun operation;
};

os_Task * os_Task_init(
    os_Task * const self,
    uint32_t const repetitionRateIn1ms, void * const client, os_Task_operationFun const operation
);
void os_Task_run(os_Task * const self);

#endif // os_Task_h
