#ifndef TIMER_H
#define TIMER_H

void     Timer_Init(void);
void     Timer_SetStamp(uint32_t Stamp);
uint32_t Timer_GetStamp(void);
void     Timer_WaitMilli(uint32_t msec);
uint32_t Timer_WaitRemainder(uint32_t StartStamp, uint32_t msec);

#endif // TIMER_H
