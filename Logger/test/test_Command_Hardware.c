#include "unity.h"

#include "Command_Hardware.h"
#include "mock_USBDriver.h"
#include "mock_Parser.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/*void test_CommandHardware_NeedToImplementInitFunction(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement CommandHardware_Init");
}*/

void test_CommandHardware_CheckForMsg_should_ReturnNoneYet_when_NoBytesAvailable(void)
{
MESSAGE_T Msg={0};

	USBDriver_OkayToRead_ExpectAndReturn(FALSE);

	TEST_ASSERT_EQUAL(STATUS_NONE_YET, CommandHardware_CheckForMsg(&Msg));
}

void test_CommandHardware_CheckForMsg_should_GetCharAndAddToPacker_when_BytesAvailable(void)
{
MESSAGE_T Msg={0};

	USBDriver_OkayToRead_ExpectAndReturn(TRUE);
	USBDriver_GetChar_ExpectAndReturn('V');
	Parser_AddChar_ExpectAndReturn('V',NULL);

	TEST_ASSERT_EQUAL(STATUS_NONE_YET, CommandHardware_CheckForMsg(&Msg));
}
