#ifndef LED_H
#define LED_H

#include "Core.h"

#define LED_PORT (LPC_GPIO1)
#define LED_PINSEL (LPC_PINCON->PINSEL3)
#define LED_PINMODE (LPC_PINCON->PINMODE3)
#define LED_PIN_BIT(bit) (0x3u << ((bit & 0x0F) << 1))
#define LED_18_BIT (18)
#define LED_20_BIT (20)
#define LED_21_BIT (21)
#define LED_23_BIT (23)

void LED_Init(void);

#endif // LED_H/
