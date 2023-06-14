#include "lib/timer/Timer.h"
#include "unity.h"

TEST_FILE("Timer.c")

#include "mock_TimeSource.h"

void setUp(void) {
}
void tearDown(void) {
}

void test_Timer_example(void) {
    TEST_ASSERT_TRUE(1);
}
