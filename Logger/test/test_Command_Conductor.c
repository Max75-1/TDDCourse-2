#include "unity.h"
#include "Core.h"
#include "mock_Command_Handlers.h"
#include "mock_Command_Hardware.h"
#include "Command_Conductor.h"

MESSAGE_T msg;

void setUp(void)
{
}

void tearDown(void)
{
}

void test_CommandConductor_Init_should_InitialiseSubmodules(void)
{
	CommandHardware_Init_Expect();
	CommandHandlers_Init_Expect();

	CommandConductor_Init();
    //TEST_IGNORE_MESSAGE("Need to Implement Command_Conductor");
}

void test_CommandConductor_Exec(void)
{
	TEST_IGNORE();
}

void test_CommandConductor_Exec_should_CheckForMessages_and_DoNothingIfNone(void)
{
	CommandHardware_Exec_Expect();
	CommandHardware_CheckForMsg_ExpectAnyArgsAndReturn(STATUS_NONE_YET);

	CommandConductor_Exec();
}

void test_CommandConductor_Exec_should_CheckForMessages_and_DoNothingIfUnknown(void)
{
	msg.Cmd = 'U'; // Unknown command

	CommandHardware_Exec_Expect();
	CommandHardware_CheckForMsg_ExpectAnyArgsAndReturn(STATUS_OK);
	CommandHardware_CheckForMsg_ReturnThruPtr_msg(&msg);

	CommandConductor_Exec();
}

void test_CommandConductor_Exec_should_CheckForMessages_and_ProccessIfVersionAndReturnResponse(void)
{
	TEST_IGNORE();
}

void test_CommandConductor_Exec_should_CheckForMessages_and_ProccessIfVersionAndHandleErrors(void)
{
	TEST_IGNORE();
}
