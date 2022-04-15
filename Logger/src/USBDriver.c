#include "USBDriver.h"

void USBDriver_Exec(void)
{
	if(serial_writable(&USBDriver_serial) && !Buffer_IsEmpty(&tx)){

	}

	if(serial_readable(&USBDriver_serial) && !Buffer_IsFull(&rx)){

	}
}
