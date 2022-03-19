#include "Analog_Model.h"

void AnalogModel_Init(void)
{
int i;

	for(i=0; i<ANALOG_NUM_CHANS; i++)
		AnalogValues[i]=0;
}

uint16_t AnalogModel_GetChannel(uint8_t Channel)
{
	if(Channel<ANALOG_NUM_CHANS)
		return AnalogValues[Channel];
	else
		return 0;
}
