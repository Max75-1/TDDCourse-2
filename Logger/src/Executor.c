#include "Executor.h"
#include "LED.h"
#include "Digital.h"
#include "Analog_Conductor.h"
#include "Analog_Model.h"

void Executor_Init(void)
{
	LED_Init();
	Digital_Init();
	AnalogConductor_Init();
}

bool Executor_Exec(void)
{
	uint8_t bits = Digital_GetBits();
	if((bits & 0x03)==0)
		LED_Off(LED0);
	else
		LED_Toggle(LED0);

	if((bits & 0x0C)==0)
		LED_Off(LED1);
	else
		LED_Toggle(LED1);

	if((bits & 0x30)==0)
		LED_Off(LED2);
	else
		LED_Toggle(LED2);

 	return true;
}

bool Executor_CompareADC(void)
{
	AnalogConductor_Exec();

	if(AnalogModel_GetChannel(0)>AnalogModel_GetChannel(1))
		LED_On(LED1);

	if(AnalogModel_GetChannel(2)>AnalogModel_GetChannel(3))
		LED_On(LED2);

	if(AnalogModel_GetChannel(4)>AnalogModel_GetChannel(5))
		LED_On(LED3);

	return true;
}

/*void Executor_RenewADC(uint8_t adc)
{
uint8_t oldValue=0;

	do{
		if(oldValue != newValue){
			LED_Blink(LED0);
			LED_Blink(LED0);
		}
	}

	return false;
}*/
