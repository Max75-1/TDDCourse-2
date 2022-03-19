#include "unity.h"

#include "mock_Analog_Model.h"
#include "mock_Analog_Hardware.h"
#include "Analog_Conductor.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/*void test_Analog_Conductor_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement Analog_Conductor");
}*/

void test_AnalogConductor_Init_should_InitSubmodules(void)
{
	AnalogModel_Init_Expect();
	AnalogHardware_Init_Expect();

	AnalogConductor_Init();
}
