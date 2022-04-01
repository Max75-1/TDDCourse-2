#ifndef COMMAND_CONDUCTOR_H
#define COMMAND_CONDUCTOR_H

#include "Defs.h"

#define COMMAND_MAX_LENGTH 40

typedef struct _MESSAGE_T
{
    char Cmd;
    char Len;
    char Data[COMMAND_MAX_LENGTH];
} MESSAGE_T;

void CommandConductor_Init(void);
void CommandConductor_Exec(void);

#endif // COMMAND_CONDUCTOR_H
