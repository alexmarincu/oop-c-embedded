#include "AccelerometerConfigDao.h"
#include "unity.h"

TEST_FILE("AccelerometerConfigDao.c")

void setUp(void) {}
void tearDown(void) {}

typedef struct {
    bool writeCalled;
    bool readCalled;
    AccelerometerConfigDao acDao;
} AccelerometerConfigDaoImpl;

static void AccelerometerConfigDaoImpl_write(AccelerometerConfigDaoImpl * const self, AccelerometerConfig * const accelerometerConfig) {
    self->writeCalled = true;
}

AccelerometerConfig * AccelerometerConfigDaoImpl_read(AccelerometerConfigDaoImpl * const self, AccelerometerConfig * const accelerometerConfig) {
    self->readCalled = true;
    return accelerometerConfig;
}

void test_AccelerometerConfigDao_functions_should_call_implementor_functions(void) {
    AccelerometerConfigDaoImpl acDaoImpl = (AccelerometerConfigDaoImpl){ 0 };
    AccelerometerConfigDao_init(
        &acDaoImpl.acDao, &acDaoImpl,
        (AccelerometerConfigDao_writeFun)AccelerometerConfigDaoImpl_write,
        (AccelerometerConfigDao_readFun)AccelerometerConfigDaoImpl_read
    );
    TEST_ASSERT_FALSE(acDaoImpl.writeCalled);
    TEST_ASSERT_FALSE(acDaoImpl.readCalled);
    AccelerometerConfigDao_write(&acDaoImpl.acDao, &(AccelerometerConfig){});
    TEST_ASSERT_TRUE(acDaoImpl.writeCalled);
    TEST_ASSERT_FALSE(acDaoImpl.readCalled);
    AccelerometerConfigDao_read(&acDaoImpl.acDao, &(AccelerometerConfig){});
    TEST_ASSERT_TRUE(acDaoImpl.writeCalled);
    TEST_ASSERT_TRUE(acDaoImpl.readCalled);
}
