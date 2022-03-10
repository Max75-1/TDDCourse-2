#include "Core.h"
#include "unity.h"
#include "cmock.h"
#include "mock_Executor.h"
#include "Main.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Main_Should_InitializeTheDriversThenCallMainLoop(void)
{
    Executor_Init_Expect();

    Executor_Exec_ExpectAndReturn(TRUE);
    Executor_Exec_ExpectAndReturn(TRUE);
    Executor_Exec_ExpectAndReturn(FALSE);

	TEST_ASSERT_EQUAL(0,TestableMain());
}

