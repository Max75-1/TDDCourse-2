#include "Filter.h"

uint16_t Filter_AddVal(uint16_t PrevVal, uint16_t NewVal)
{
	return ((3*(uint32_t)PrevVal+(uint32_t)NewVal+2)/4);
}
