#include "Core.h"
#include "Command_Hardware.h"
#include "USBDriver.h"
#include "Parser.h"
#include "Packer.h"
#include "Utils.h"

STATIC char DataOut[USB_MAX_BUFFER_LENGTH];

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

STATUS_T CommandHardware_SendResponse(MESSAGE_T *Msg)
{
char *PacketOut;

	HexToBin(Msg->Data, DataOut, Msg->Len);
	PacketOut=Packer_AddMsg(Msg->Cmd, Msg->Data, Msg->Len);
	if(PacketOut==NULL)
		return STATUS_BAD_MSG;

	return STATUS_UNKNOWN_ERR;
}
