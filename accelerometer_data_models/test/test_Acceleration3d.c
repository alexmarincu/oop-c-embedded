#include "Acceleration3d.h"
#include "unity.h"

TEST_FILE("Acceleration3d.c")

void setUp(void) {}
void tearDown(void) {}

void test_Acceleration3d_magnitude_should_calculate_the_magnitude_of_self(void) {
    TEST_ASSERT_EQUAL(1, Acceleration3d_magnitude(&(Acceleration3d){ .x = 1, .y = 1, .z = 1 }));
    TEST_ASSERT_EQUAL(5, Acceleration3d_magnitude(&(Acceleration3d){ .x = 2, .y = 3, .z = 4 }));
}

void test_Acceleration3d_plus_should_add_self_to_other(void) {
    Acceleration3d * a3d = Acceleration3d_plus(&(Acceleration3d){ .x = 1, .y = 1, .z = 1 }, &(Acceleration3d){ .x = 2, .y = 3, .z = 4 });
    TEST_ASSERT_EQUAL(3, a3d->x);
    TEST_ASSERT_EQUAL(4, a3d->y);
    TEST_ASSERT_EQUAL(5, a3d->z);
}

void test_Acceleration3d_div_should_divide_self_to_the_provided_value(void) {
    Acceleration3d * a3d = Acceleration3d_div(&(Acceleration3d){ .x = 2, .y = 4, .z = 6 }, 2);
    TEST_ASSERT_EQUAL(1, a3d->x);
    TEST_ASSERT_EQUAL(2, a3d->y);
    TEST_ASSERT_EQUAL(3, a3d->z);
}
