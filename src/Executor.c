#include "Executor.h"
#include "LED.h"
#include "Digital.h"

void Executor_Init(void)
{
	LED_Init();
	Digital_Init();
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
