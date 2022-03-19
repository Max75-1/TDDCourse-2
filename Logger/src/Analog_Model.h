#ifndef ANALOG_MODEL_H
#define ANALOG_MODEL_H

#include <stdint.h>
#include "Core.h"

uint16_t AnalogValues[ANALOG_NUM_CHANS];

void AnalogModel_Init(void);
uint16_t AnalogModel_GetChannel(uint8_t Channel);


#endif // ANALOG_MODEL_H
