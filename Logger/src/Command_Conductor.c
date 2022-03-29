#include "Command_Handlers.h"
#include "Command_Hardware.h"
#include "Command_Conductor.h"

void CommandConductor_Init(void)
{
	CommandHardware_Init();
	CommandHandlers_Init();
}

void CommandConductor_Exec(void)
{
MESSAGE_T msg;

	CommandHardware_Exec();

	if(CommandHardware_CheckForMsg(&msg)== STATUS_OK ){

	}
}
