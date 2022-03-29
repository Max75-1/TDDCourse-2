#ifndef COMMAND_HARDWARE_H
#define COMMAND_HARDWARE_H

//#include "Defs.h"
#include "Command_Conductor.h"

void CommandHardware_Init(void);
void CommandHardware_Exec(void);
STATUS_T CommandHardware_CheckForMsg(MESSAGE_T *msg);

#endif // COMMAND_HARDWARE_H
