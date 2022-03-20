#include "Analog_Model.h"
#include "Filter.h"

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

void AnalogModel_AddReading(uint8_t Channel, uint16_t Reading)
{
	if(Channel < ANALOG_NUM_CHANS)
		AnalogValues[Channel]=Filter_AddVal(AnalogValues[Channel], Reading);
}
