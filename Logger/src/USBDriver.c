#include "USBDriver.h"
#include <stdbool.h>

void USBDriver_Init(void)
{
	serial_init(&USBDriver_serial, USBTX, USBRX);
	serial_clear(&USBDriver_serial);

	Buffer_Init(&tx, tx_data, USB_BUFFER_MAX);
	Buffer_Init(&rx, rx_data, USB_BUFFER_MAX);

	initialized=TRUE;
}

void USBDriver_Exec(void)
{
uint8_t Val;

	if( serial_writable(&USBDriver_serial) && !Buffer_IsEmpty(&tx) && (STATUS_OK==Buffer_Get(&tx, &Val))){
		serial_putc(&USBDriver_serial, Val);
	}

	if(serial_readable(&USBDriver_serial) && !Buffer_IsFull(&rx)){
		Val = serial_getc(&USBDriver_serial);
		Buffer_Put(&rx, Val);
	}
}

bool USBDriver_Connected(void)
{
	return initialized;
}

bool USBDriver_OkayToRead() { return FALSE; }
char USBDriver_GetChar(void)
{
	 uint8_t Val;
	 if (Buffer_Get(&rx, &Val) == STATUS_OK)
	     return (char)Val;
	 else
	     return 0x00;
}

bool USBDriver_PutChar(char Val)
{
	if (Buffer_IsFull(&tx))
	    return FALSE;

	Buffer_Put(&tx, Val);

	return TRUE;
}
