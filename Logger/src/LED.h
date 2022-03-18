#ifndef LED_H
#define LED_H

#include "Core.h"
//#include "Timer.h"

#define LED_PORT (LPC_GPIO1)
#define LED_PINSEL (LPC_PINCON->PINSEL3)
#define LED_PINMODE (LPC_PINCON->PINMODE3)
#define LED_PIN_BIT(bit) (0x3u << ((bit & 0x0F) << 1))
#define LED_0_BIT (18)
#define LED_1_BIT (20)
#define LED_2_BIT (21)
#define LED_3_BIT (23)

typedef enum LED_ID_T {LED0=0,LED1,LED2,LED3,NUM_LED} LED_ID_T;

void LED_Init(void);
void LED_Toggle(LED_ID_T id);
void LED_On(LED_ID_T id);
void LED_Off(LED_ID_T id);
void LED_Blink(LED_ID_T id);

#endif // LED_H/
