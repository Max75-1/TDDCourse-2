#ifndef COMMAND_MODEL_H
#define COMMAND_MODEL_H

#include "Command_Conductor.h"

void CommandHandlers_Init(void);
STATUS_T CommandHandlerVersion(MESSAGE_T* Msg);
STATUS_T CommandHandlerClock(MESSAGE_T* Msg);
STATUS_T CommandHandlerResults(MESSAGE_T* Msg);

#endif // COMMAND_MODEL_H
