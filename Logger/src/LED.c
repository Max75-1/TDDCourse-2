#include "LED.h"
//#include "Timer.h"

void LED_Init(void)
{
	// set low LED-pins to GPIO
	LED_PINSEL= ~( LED_PIN_BIT(LED_0_BIT) | LED_PIN_BIT(LED_1_BIT) | LED_PIN_BIT(LED_2_BIT) | LED_PIN_BIT(LED_3_BIT));

	// enable IO on these pins
	LED_PORT->FIOMASK= ~(BIT_TO_MASK(LED_0_BIT) | BIT_TO_MASK(LED_1_BIT) | BIT_TO_MASK(LED_2_BIT) | BIT_TO_MASK(LED_3_BIT));

	// enable LED-pins as outputs
	LED_PORT->FIODIR= BIT_TO_MASK(LED_0_BIT) | BIT_TO_MASK(LED_1_BIT) | BIT_TO_MASK(LED_2_BIT) | BIT_TO_MASK(LED_3_BIT);

	// enable pulldowns for these LEDs
	LED_PINMODE = ~( LED_PIN_BIT(LED_0_BIT) | LED_PIN_BIT(LED_1_BIT) | LED_PIN_BIT(LED_2_BIT) | LED_PIN_BIT(LED_3_BIT));

	// Set high LED18 and set low others LEDs
	LED_PORT->FIOSET= BIT_TO_MASK(LED_0_BIT);
	LED_PORT->FIOCLR=  BIT_TO_MASK(LED_1_BIT) | BIT_TO_MASK(LED_2_BIT) | BIT_TO_MASK(LED_3_BIT);

}

/*void LED_Blink(LED_ID_T id)
{
	Timer_WaitMilli(250);
	LED_Toggle(id);
	Timer_WaitMilli(250);
	LED_Toggle(id);

}*/

void LED_On(LED_ID_T id)
{
int LedBit;

	switch(id){
		case LED0 : LedBit=LED_0_BIT; break;
		case LED1 : LedBit=LED_1_BIT; break;
		case LED2 : LedBit=LED_2_BIT; break;
		case LED3 : LedBit=LED_3_BIT; break;
		default: return;
	}

	LED_PORT->FIOSET= BIT_TO_MASK(LedBit);
}

void LED_Off(LED_ID_T id)
{
int LedBit;

	switch(id){
		case LED0 : LedBit=LED_0_BIT; break;
		case LED1 : LedBit=LED_1_BIT; break;
		case LED2 : LedBit=LED_2_BIT; break;
		case LED3 : LedBit=LED_3_BIT; break;
		default: return;
	}

	LED_PORT->FIOCLR= BIT_TO_MASK(LedBit);
}

void LED_Toggle(LED_ID_T id)
{
int LedBit;
uint32_t mask;

	switch(id){
		case LED0 : LedBit=LED_0_BIT; break;
		case LED1 : LedBit=LED_1_BIT; break;
		case LED2 : LedBit=LED_2_BIT; break;
		case LED3 : LedBit=LED_3_BIT; break;
		default: return;
	}

	mask=BIT_TO_MASK(LedBit);
	if( (LED_PORT->FIOSET & mask)==mask )
		LED_PORT->FIOCLR= mask;
	else
		LED_PORT->FIOSET= mask;
}


