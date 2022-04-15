#include "USBDriver.h"
<<<<<<< HEAD

=======
#include <stdbool.h>




void USBDriver_Init(void)
{
	serial_init(&USBDriver_serial, USBTX, USBRX);
	serial_clear(&USBDriver_serial);

	Buffer_Init(&tx, tx_data, USB_BUFFER_MAX);
	Buffer_Init(&rx, rx_data, USB_BUFFER_MAX);

	initialized=TRUE;
}
>>>>>>> serial&USB
void USBDriver_Exec(void)
{
	if(serial_writable(&USBDriver_serial) && !Buffer_IsEmpty(&tx)){

	}

	if(serial_readable(&USBDriver_serial) && !Buffer_IsFull(&rx)){

	}
}
<<<<<<< HEAD
=======

bool USBDriver_Connected(void) { return FALSE; }
bool USBDriver_OkayToRead() { return FALSE; }
char USBDriver_GetChar(void) { return '!'; }
bool USBDriver_PutChar(char Val) { return FALSE; }

>>>>>>> serial&USB
