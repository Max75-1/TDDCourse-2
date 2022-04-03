#include "Command_Hardware.h"
#include "USBDriver.h"
#include "Parser.h"
#include "Utils.h"

STATUS_T CommandHardware_CheckForMsg(MESSAGE_T *msg)
{
	if(USBDriver_OkayToRead()){
		char byte= USBDriver_GetChar();
		char *ParsedPacket = Parser_AddChar(byte);
		if( ParsedPacket != NULL){
			msg->Cmd=ParsedPacket[1];
			msg->Len=(ParsedPacket[2]-'0');
			HexToBin(&ParsedPacket[3],msg->Data, msg->Len);
			return STATUS_OK;
		}
	}

	return STATUS_NONE_YET;
}
