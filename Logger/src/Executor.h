#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <stdbool.h>

void Executor_Init(void);
bool Executor_Exec(void);
bool Executor_CompareADC(void);
//void Executor_RenewADC(uint8_t adc);

#endif // EXECUTOR_H
