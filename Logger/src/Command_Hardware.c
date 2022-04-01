#include "Command_Hardware.h"
#include "USBDriver.h"

STATUS_T CommandHardware_CheckForMsg(MESSAGE_T *msg)
{
	if(USBDriver_OkayToRead())
		return STATUS_UNKNOWN_ERR;
	else
		return STATUS_NONE_YET;
}
