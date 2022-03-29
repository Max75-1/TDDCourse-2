#include "Core.h"
#include "Main.h"
#include "Executor.h"
#include "Timer.h"


//
// NOTE: Do not attempt to test main() directly.
//       See Lecture 9 for how to handle this special case.
// ========================================================
//

#ifndef TEST
int main(void)
#else
int TestableMain(void)
#endif
{
uint32_t LastTick;

	Executor_Init();
	LastTick=Timer_GetStamp();

	while(Executor_Exec()){
		LastTick=Timer_WaitRemainder(LastTick, MAIN_TICK_MSEC );
	}
    return 0;
}
