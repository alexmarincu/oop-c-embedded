#ifndef Task_h
#define Task_h
#include <stdint.h>

typedef struct Task Task;
typedef void (*Task_operationFun)(void * const self);
struct Task {
    uint32_t startTimeAtLastRunIn1ms;
    uint32_t maxRunDurationIn1ms;
    uint32_t repetitionRateIn1ms;
    void * client;
    Task_operationFun operation;
};

Task * Task_init(
    Task * const self,
    uint32_t const repetitionRateIn1ms, void * const client, Task_operationFun const operation
);
void Task_run(Task * const self);

#endif // Task_h
