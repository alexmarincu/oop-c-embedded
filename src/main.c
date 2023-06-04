#include "SimOs.h"

int main(void) {
    SimOs * simOs = SimOs_init(SimOs_getInstance());
    SimOs_main(simOs);
    return 0;
}
