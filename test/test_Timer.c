#include "Timer.h"
#include "unity.h"

TEST_FILE("Timer.c")
TEST_FILE("TimerClass.c")

#include "mock_TimeSource.h"

void setUp(void) {
}
void tearDown(void) {
}

void test_App_example(void) {
    TEST_ASSERT_TRUE(1);
}
