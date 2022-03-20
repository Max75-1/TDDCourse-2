#ifndef ANALOG_MODEL_H
#define ANALOG_MODEL_H

#include <stdint.h>
#include "Core.h"

static uint16_t AnalogValues[ANALOG_NUM_CHANS];

void AnalogModel_Init(void);
uint16_t AnalogModel_GetChannel(uint8_t Channel);
void     AnalogModel_AddReading(uint8_t Channel, uint16_t Reading);


#endif // ANALOG_MODEL_H
