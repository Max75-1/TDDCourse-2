#ifndef ANALOG_H
#define ANALOG_H

#include "Core.h"

//LPC_ADC_TypeDef ADC[]={ADDR0,ADDR1,ADDR2,ADDR3,ADDR4,ADDR5};
#define ADC0 LPC_ADC->ADDR0
#define ADC1 LPC_ADC->ADDR1
#define ADC2 LPC_ADC->ADDR2
#define ADC3 LPC_ADC->ADDR3
#define ADC4 LPC_ADC->ADDR4
#define ADC5 LPC_ADC->ADDR5

void Analog_Init(void);
uint32_t Analog_GetChannel(uint8_t Channel );

#endif // ANALOG_H
