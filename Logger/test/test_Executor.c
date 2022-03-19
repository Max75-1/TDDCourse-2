#include "unity.h"
#include "mock_LED.h"
#include "mock_Digital.h"
#include "mock_Analog_Conductor.h"
#include "Executor.h"
#include "mock_Analog_Model.h"
//#include "LED.h"
//#include "Timer.h"

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
	AnalogConductor_Init_Expect();

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

void test_Executor_ADC_should_SetLED1On_when_ADC0BiggerThanADC1(void)
{
	/*ADC0=0x2;
	ADC1=0x1;
	ADC2=0x3;
	ADC3=0x4;
	ADC4=0x5;
	ADC5=0x6;*/

	AnalogConductor_Exec_Expect();

	AnalogModel_GetChannel_ExpectAndReturn(0,0x2);
	AnalogModel_GetChannel_ExpectAndReturn(1,0x1);
	LED_On_Expect(LED1);

	AnalogModel_GetChannel_ExpectAndReturn(2,0x3);
	AnalogModel_GetChannel_ExpectAndReturn(3,0x4);

	AnalogModel_GetChannel_ExpectAndReturn(4,0x5);
	AnalogModel_GetChannel_ExpectAndReturn(5,0x6);

	Executor_CompareADC();
	//TEST_ASSERT_FALSE(Executor_ADC());
}

void test_Executor_ADC_should_SetLED2On_when_ADC2BiggerThanADC3(void)
{
	/*ADC0=0x1;
	ADC1=0x2;
	ADC2=0x4;
	ADC3=0x3;
	ADC4=0x5;
	ADC5=0x6;*/

	AnalogConductor_Exec_Expect();

	AnalogModel_GetChannel_ExpectAndReturn(0,0x1);
	AnalogModel_GetChannel_ExpectAndReturn(1,0x2);

	AnalogModel_GetChannel_ExpectAndReturn(2,0x4);
	AnalogModel_GetChannel_ExpectAndReturn(3,0x3);
	LED_On_Expect(LED2);

	AnalogModel_GetChannel_ExpectAndReturn(4,0x5);
	AnalogModel_GetChannel_ExpectAndReturn(5,0x6);

	Executor_CompareADC();
}

void test_Executor_ADC_should_SetLED3On_when_ADC4BiggerThanADC5(void)
{
	/*ADC0=0x1;
	ADC1=0x2;
	ADC2=0x3;
	ADC3=0x4;
	ADC4=0x6;
	ADC5=0x5;*/

	AnalogConductor_Exec_Expect();

	AnalogModel_GetChannel_ExpectAndReturn(0,0x1);
	AnalogModel_GetChannel_ExpectAndReturn(1,0x2);

	AnalogModel_GetChannel_ExpectAndReturn(2,0x3);
	AnalogModel_GetChannel_ExpectAndReturn(3,0x4);

	AnalogModel_GetChannel_ExpectAndReturn(4,0x6);
	AnalogModel_GetChannel_ExpectAndReturn(5,0x5);
	LED_On_Expect(LED3);

	Executor_CompareADC();
}
