#ifndef DIGITAL_H
#define DIGITAL_H

#include "stdint.h"
#include "Core.h"

#define DIGITAL_PORT     LPC_GPIO2
#define DIGITAL_PINSEL   LPC_PINCON->PINSEL4
#define DIGITAL_PINMODE  LPC_PINCON->PINMODE4

void Digital_Init(void);
uint8_t Digital_GetBits(void);

#endif // DIGITAL_H
