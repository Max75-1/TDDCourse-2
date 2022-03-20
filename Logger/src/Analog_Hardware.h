#ifndef ANALOG_HARDWARE_H
#define ANALOG_HARDWARE_H

#include "Core.h"

void AnalogHardware_Init(void);
STATUS_T AnalogHardware_IsReady(uint8_t Channel);
uint16_t AnalogHardware_GetReading(uint8_t channel);

#endif // ANALOG_HARDWARE_H
