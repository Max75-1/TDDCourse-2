#ifndef USBDRIVER_H
#define USBDRIVER_H

#include <stdbool.h>

bool USBDriver_OkayToRead();
char USBDriver_GetChar(void);
bool USBDriver_PutChar(char Val);


#endif // USBDRIVER_H
