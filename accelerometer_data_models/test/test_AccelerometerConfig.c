#include "AccelerometerConfig.h"
#include "unity.h"

TEST_FILE("AccelerometerConfig.c")

void setUp(void) {}
void tearDown(void) {}

void test_AccelerometerConfig_isEqual_should_check_if_self_is_equal_to_other(void) {
    TEST_ASSERT_TRUE(
        AccelerometerConfig_isEqual(
            &(AccelerometerConfig){ .isSimulatorEnabled = false },
            &(AccelerometerConfig){ .isSimulatorEnabled = false }
        )
    );
    TEST_ASSERT_FALSE(
        AccelerometerConfig_isEqual(
            &(AccelerometerConfig){ .isSimulatorEnabled = false },
            &(AccelerometerConfig){ .isSimulatorEnabled = true }
        )
    );
}
