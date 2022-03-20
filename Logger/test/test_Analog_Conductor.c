#include "unity.h"
#include "Core.h"
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

void test_AnalogConductor_Exec_should_NotUpdateTheModelIfNoChannelsReady(void)
{
	AnalogHardware_IsReady_ExpectAndReturn(0, STATUS_NONE_YET);
	AnalogHardware_IsReady_ExpectAndReturn(1, STATUS_NONE_YET);
	AnalogHardware_IsReady_ExpectAndReturn(2, STATUS_NONE_YET);
	AnalogHardware_IsReady_ExpectAndReturn(3, STATUS_NONE_YET);
	AnalogHardware_IsReady_ExpectAndReturn(4, STATUS_NONE_YET);
	AnalogHardware_IsReady_ExpectAndReturn(5, STATUS_NONE_YET);

	AnalogConductor_Exec();
}

void test_AnalogConductor_Exec_should_UpdateTheModelForChannelWithData(void)
{
	AnalogHardware_IsReady_ExpectAndReturn(0, STATUS_OK);
	AnalogHardware_GetReading_ExpectAndReturn(0, 0x1234);
	AnalogModel_AddReading_Expect(0,0x1234);

	AnalogHardware_IsReady_ExpectAndReturn(1, STATUS_NONE_YET);
	AnalogHardware_IsReady_ExpectAndReturn(2, STATUS_NONE_YET);
	AnalogHardware_IsReady_ExpectAndReturn(3, STATUS_NONE_YET);
	AnalogHardware_IsReady_ExpectAndReturn(4, STATUS_NONE_YET);
	AnalogHardware_IsReady_ExpectAndReturn(5, STATUS_NONE_YET);

	AnalogConductor_Exec();
}

void test_AnalogConductor_Exec_should_UpdateTheModelForOtherChannelsWithData(void)
{
	AnalogHardware_IsReady_ExpectAndReturn(0, STATUS_NONE_YET);
	AnalogHardware_IsReady_ExpectAndReturn(1, STATUS_NONE_YET);
	AnalogHardware_IsReady_ExpectAndReturn(2, STATUS_NONE_YET);
	AnalogHardware_IsReady_ExpectAndReturn(3, STATUS_NONE_YET);
	AnalogHardware_IsReady_ExpectAndReturn(4, STATUS_OK);
	AnalogHardware_GetReading_ExpectAndReturn(4, 0x5A5A);
	AnalogModel_AddReading_Expect(4,0x5A5A);

	AnalogHardware_IsReady_ExpectAndReturn(5, STATUS_OK);
	AnalogHardware_GetReading_ExpectAndReturn(5, 0xA5A5);
	AnalogModel_AddReading_Expect(5,0xA5A5);

	AnalogConductor_Exec();
}
