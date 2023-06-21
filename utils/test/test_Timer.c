#include "Timer.h"
#include "unity.h"

TEST_FILE("Timer.c")

#include "mock_TimeSource.h"

void setUp(void) {}
void tearDown(void) {}

void test_Timer_should_not_be_running_or_expired_after_init(void) {
    Timer * t = Timer_init(&(Timer){});
    TEST_ASSERT_FALSE(Timer_isRunning(t));
    TEST_ASSERT_FALSE(Timer_isExpired(t));
}

void test_Timer_should_be_running_after_start(void) {
    Timer * t = Timer_init(&(Timer){});
    TimeSource_getCurrentOpTimeIn1ms_ExpectAndReturn(100);
    Timer_start(t, 1000);
    TEST_ASSERT_TRUE(Timer_isRunning(t));
}

void test_Timer_should_not_be_expired_after_start_if_duration_is_not_elapsed(void) {
    Timer * t = Timer_init(&(Timer){});
    TimeSource_getCurrentOpTimeIn1ms_ExpectAndReturn(100);
    Timer_start(t, 1000);
    TimeSource_getCurrentOpTimeIn1ms_ExpectAndReturn(1099);
    TEST_ASSERT_FALSE(Timer_isExpired(t));
}

void test_Timer_should_be_running_and_expired_after_start_if_duration_is_elapsed(void) {
    Timer * t = Timer_init(&(Timer){});
    TimeSource_getCurrentOpTimeIn1ms_ExpectAndReturn(100);
    Timer_start(t, 1000);
    TimeSource_getCurrentOpTimeIn1ms_ExpectAndReturn(1100);
    TEST_ASSERT_TRUE(Timer_isExpired(t));
    TEST_ASSERT_TRUE(Timer_isRunning(t));
}

void test_Timer_should_not_be_running_or_expired_if_stopped_before_expiration(void) {
    Timer * t = Timer_init(&(Timer){});
    TimeSource_getCurrentOpTimeIn1ms_ExpectAndReturn(100);
    Timer_start(t, 1000);
    Timer_stop(t);
    TEST_ASSERT_FALSE(Timer_isRunning(t));
    TEST_ASSERT_FALSE(Timer_isExpired(t));
}

void test_Timer_should_not_be_running_or_expired_if_stopped_after_expiration(void) {
    Timer * t = Timer_init(&(Timer){});
    TimeSource_getCurrentOpTimeIn1ms_ExpectAndReturn(100);
    Timer_start(t, 1000);
    TimeSource_getCurrentOpTimeIn1ms_ExpectAndReturn(1100);
    TEST_ASSERT_TRUE(Timer_isExpired(t));
    Timer_stop(t);
    TEST_ASSERT_FALSE(Timer_isRunning(t));
    TEST_ASSERT_FALSE(Timer_isExpired(t));
}