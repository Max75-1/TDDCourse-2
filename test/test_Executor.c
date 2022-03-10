#include "unity.h"
#include "mock_LED.h"
#include "mock_Digital.h"
#include "Executor.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Executor_Init_should_InitialiseAllSubsystems(void)
{
	LED_Init_Expect();
	Digital_Init_Expect();

	Executor_Init();
    //TEST_IGNORE_MESSAGE("Need to Implement Executor Init");
}

void test_Executor_Exec_should_ToggleLed0_when_Digital0or1AreHigh(void)
{
	Digital_GetBits_ExpectAndReturn(0x01);
	LED_Toggle_Expect(LED0);
	Executor_Exec();
	/*TEST_ASSERT_TRUE(Executor_Exec());
	TEST_ASSERT_TRUE(Executor_Exec());
	TEST_ASSERT_TRUE(Executor_Exec());*/
    //TEST_IGNORE_MESSAGE("Need to Implement Executor Exec");
}
