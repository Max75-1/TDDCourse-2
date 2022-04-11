#ifndef USBDRIVER_H
#define USBDRIVER_H

#include "Core.h"
#include "serial_api.h"
#include "Buffer.h"
#include <stdbool.h>

#define USB_BUFFER_MAX (75)

static serial_t USBDriver_serial;
static uint8_t tx_data[USB_BUFFER_MAX];
static uint8_t rx_data[USB_BUFFER_MAX];
static BUFFER_T tx;
static BUFFER_T rx;

static bool initialized=FALSE;

void USBDriver_Init(void);
void USBDriver_Exec(void);

bool USBDriver_Connected(void);
bool USBDriver_OkayToRead();
char USBDriver_GetChar(void);
bool USBDriver_PutChar(char Val);


#endif // USBDRIVER_H
