#ifndef USBDRIVER_H
#define USBDRIVER_H

#include <stdbool.h>

void USBDriver_Init(void);
void USBDriver_Exec(void);

bool USBDriver_Connected(void);
bool USBDriver_OkayToRead();
char USBDriver_GetChar(void);
bool USBDriver_PutChar(char Val);


#endif // USBDRIVER_H
