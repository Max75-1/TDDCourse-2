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

void test_Executor_Exec_should_ToggleLed0_when_Digital0IsHigh(void)
{
	Digital_GetBits_ExpectAndReturn(0x01);
	LED_Toggle_Expect(LED0);

	LED_Off_Expect(LED1);
	LED_Off_Expect(LED2);

	Executor_Exec();

}

void test_Executor_Exec_should_ToggleLed0_when_Digital1IsHigh(void)
{
	Digital_GetBits_ExpectAndReturn(0x02);
	LED_Toggle_Expect(LED0);

	LED_Off_Expect(LED1);
	LED_Off_Expect(LED2);

	Executor_Exec();

}

void test_Executor_Exec_should_ToggleLed0_when_Digital0and1AreHigh(void)
{
	Digital_GetBits_ExpectAndReturn(0x03);
	LED_Toggle_Expect(LED0);

	LED_Off_Expect(LED1);
	LED_Off_Expect(LED2);

	Executor_Exec();

}

void test_Executor_Exec_should_NotToggleLed0_when_Digital0And1AreLow(void)
{
	Digital_GetBits_ExpectAndReturn(0x00);
	LED_Off_Expect(LED0);

	LED_Off_Expect(LED1);
	LED_Off_Expect(LED2);

	Executor_Exec();
}

void test_Executor_Exec_should_ToggleLed1_when_Digital2IsHigh(void)
{
	Digital_GetBits_ExpectAndReturn(0x04);
	LED_Off_Expect(LED0);
	LED_Toggle_Expect(LED1);
	LED_Off_Expect(LED2);

	Executor_Exec();

}

void test_Executor_Exec_should_ToggleLed2_when_Digital4IsHigh(void)
{
	Digital_GetBits_ExpectAndReturn(0x10);
	LED_Off_Expect(LED0);
	LED_Off_Expect(LED1);
	LED_Toggle_Expect(LED2);

	Executor_Exec();

}

void test_Executor_Exec_should_ToggleLed1_when_Digital3IsHigh(void)
{
	Digital_GetBits_ExpectAndReturn(0x08);
	LED_Off_Expect(LED0);
	LED_Toggle_Expect(LED1);
	LED_Off_Expect(LED2);

	Executor_Exec();

}

void test_Executor_Exec_should_ToggleLed2_when_Digital5IsHigh(void)
{
	Digital_GetBits_ExpectAndReturn(0x20);
	LED_Off_Expect(LED0);
	LED_Off_Expect(LED1);
	LED_Toggle_Expect(LED2);

	Executor_Exec();

}

void test_Executor_Exec_should_ToggleLed1_when_Digital2and3AreHigh(void)
{
	Digital_GetBits_ExpectAndReturn(0x0C);
	LED_Off_Expect(LED0);
	LED_Toggle_Expect(LED1);
	LED_Off_Expect(LED2);

	Executor_Exec();

}

void test_Executor_Exec_should_NotToggleLed1_when_Digital2And3AreLow(void)
{
	Digital_GetBits_ExpectAndReturn(0x00);
	LED_Off_Expect(LED0);
	LED_Off_Expect(LED1);
	LED_Off_Expect(LED2);

	Executor_Exec();
}

void test_Executor_Exec_should_ToggleLed2_when_Digital4and5AreHigh(void)
{
	Digital_GetBits_ExpectAndReturn(0x30);
	LED_Off_Expect(LED0);
	LED_Off_Expect(LED1);
	LED_Toggle_Expect(LED2);

	Executor_Exec();

}

void test_Executor_Exec_should_NotToggleLed2_when_Digital4And5AreLow(void)
{
	Digital_GetBits_ExpectAndReturn(0x00);
	LED_Off_Expect(LED0);
	LED_Off_Expect(LED1);
	LED_Off_Expect(LED2);

	Executor_Exec();
}
