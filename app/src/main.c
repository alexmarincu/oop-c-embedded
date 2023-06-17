#include "os/Os.h"

int main(void) {
    Os * os = Os_init(Os_getInstance());
    Os_run(os);
    return 0;
}
