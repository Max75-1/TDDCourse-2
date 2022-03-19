#include "unity.h"

#include "Analog_Model.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/*void test_Analog_Model_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement Analog_Model");
}*/

void test_AnalogModel_GetChannel_should_ReturnZero_when_ChannelIllegal(void)
{
	TEST_ASSERT_EQUAL_HEX16(0,AnalogModel_GetChannel(ANALOG_NUM_CHANS));
}

void test_AnalogModel_GetChannel_should_ReturnZero_when_NoValueCapturedYet(void)
{
	AnalogModel_Init();

	TEST_ASSERT_EQUAL_HEX16(0,AnalogModel_GetChannel(0));
	TEST_ASSERT_EQUAL_HEX16(0,AnalogModel_GetChannel(ANALOG_NUM_CHANS - 1));
}

