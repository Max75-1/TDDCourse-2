#include "Executor.h"
#include "LED.h"
#include "Digital.h"

void Executor_Init(void)
{
	LED_Init();
	Digital_Init();
}

bool Executor_Exec(void)
{
	return true;
}
