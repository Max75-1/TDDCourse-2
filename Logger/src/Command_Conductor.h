#ifndef COMMAND_CONDUCTOR_H
#define COMMAND_CONDUCTOR_H

#include "Defs.h"

typedef struct MESSAGE_T {
	char Cmd;
} MESSAGE_T;

void CommandConductor_Init(void);
void CommandConductor_Exec(void);

#endif // COMMAND_CONDUCTOR_H
