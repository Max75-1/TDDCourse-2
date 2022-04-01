#ifndef USBDRIVER_H
#define USBDRIVER_H

#include <stdbool.h>

bool USBDriver_OkayToRead();
char USBDriver_GetChar(void);


#endif // USBDRIVER_H
