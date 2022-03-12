
#include "Digital.h"

void Digital_Init(void)
{
//uint32_t mask=0;
	//All our Digital I/O are going to be inputs
    DIGITAL_PORT->FIOMASK &= ~MASK_RANGE(0, 5);
    DIGITAL_PORT->FIODIR  &= ~MASK_RANGE(0, 5);

    //Clear pin select bits for bits we plan to use to make them GPIO pins
    DIGITAL_PINSEL &= ~MASK_RANGE_PAIRS(0, 5, 0x3);

    //All inputs are connected to pulldowns
    //mask = DIGITAL_PINMODE;
    DIGITAL_PINMODE |= MASK_RANGE_PAIRS(0, 5, 0x3);
    //DIGITAL_PINMODE = mask;
}

uint8_t Digital_GetBits(void)
{
    uint32_t bits = DIGITAL_PORT->FIOPIN;

    //remove bits above our range
    bits &= ((2 << 5 ) - 1);

    //shift bits down to bottom
    bits = bits >> 0;

    return (uint8_t)bits;
}
