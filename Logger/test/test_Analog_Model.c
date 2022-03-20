#include "unity.h"
#include "mock_Filter.h"
#include "Analog_Model.h"

void setUp(void)
{
	AnalogModel_Init();
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
	TEST_ASSERT_EQUAL_HEX16(0,AnalogModel_GetChannel(0));
	TEST_ASSERT_EQUAL_HEX16(0,AnalogModel_GetChannel(ANALOG_NUM_CHANS - 1));
}

void test_AnalogModel_GetChannel_should_ReturnLatestDataForChan0(void)
{
	Filter_AddVal_ExpectAndReturn(0x0000,0x1234,0x4321);
	AnalogModel_AddReading(0,0x1234);

	TEST_ASSERT_EQUAL_HEX16(0x4321,AnalogModel_GetChannel(0));
	TEST_ASSERT_EQUAL_HEX16(0,AnalogModel_GetChannel(1));
	TEST_ASSERT_EQUAL_HEX16(0,AnalogModel_GetChannel(ANALOG_NUM_CHANS - 1));
}

void test_AnalogModel_GetChannel_should_NotCareAboutStaleness(void)
{
	Filter_AddVal_ExpectAndReturn(0,11,4);
	AnalogModel_AddReading(0,11);
	Filter_AddVal_ExpectAndReturn(0,22,6);
	AnalogModel_AddReading(1,22);

	TEST_ASSERT_EQUAL_HEX16(4,AnalogModel_GetChannel(0));
	TEST_ASSERT_EQUAL_HEX16(6,AnalogModel_GetChannel(1));
	TEST_ASSERT_EQUAL_HEX16(0,AnalogModel_GetChannel(2));

	Filter_AddVal_ExpectAndReturn(6,222,60);
	AnalogModel_AddReading(1,222);
	Filter_AddVal_ExpectAndReturn(0,333,83);
	AnalogModel_AddReading(3,333);

	TEST_ASSERT_EQUAL_HEX16(4,AnalogModel_GetChannel(0));
	TEST_ASSERT_EQUAL_HEX16(60,AnalogModel_GetChannel(1));
	TEST_ASSERT_EQUAL_HEX16(83,AnalogModel_GetChannel(3));
}

