#include "unity.h"
#include "Core.h"
#include "mock_Command_Handlers.h"
#include "mock_Command_Hardware.h"
#include "Command_Conductor.h"

MESSAGE_T msg;
MESSAGE_T rsp;

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
	CommandHardware_SendError_ExpectAndReturn( &msg, STATUS_UNKNOWN_CMD, STATUS_OK );

	CommandConductor_Exec();
}

void test_CommandConductor_Exec_should_CheckForMessages_and_ProccessIfVersionAndReturnResponse(void)
{
	msg.Cmd = 'V'; //Version Command
	rsp.Cmd = 'v'; //Something different to show it's a response

	CommandHardware_Exec_Expect();
	CommandHardware_CheckForMsg_ExpectAnyArgsAndReturn( STATUS_OK );
	CommandHardware_CheckForMsg_ReturnThruPtr_msg( &msg );
	CommandHandlerVersion_ExpectAndReturn( &msg, STATUS_OK );
	CommandHandlerVersion_ReturnThruPtr_Msg( &rsp );
	CommandHardware_SendResponse_ExpectAndReturn( &rsp, STATUS_OK );

	CommandConductor_Exec();
}

void test_CommandConductor_Exec_should_CheckForMessages_and_ProccessIfVersionAndHandleErrors(void)
{
	 msg.Cmd = 'V'; //Version Command
	 rsp.Cmd = 'v'; //Something different to show it's a response

	 CommandHardware_Exec_Expect();
	 CommandHardware_CheckForMsg_ExpectAnyArgsAndReturn( STATUS_OK );
	 CommandHardware_CheckForMsg_ReturnThruPtr_msg( &msg );
	 CommandHandlerVersion_ExpectAndReturn( &msg, STATUS_EXTRA_ARG );
	 CommandHandlerVersion_ReturnThruPtr_Msg( &rsp );
	 CommandHardware_SendError_ExpectAndReturn( &rsp, STATUS_EXTRA_ARG, STATUS_OK );

	 CommandConductor_Exec();
}
