#include "TM4C123GH6PM.h"

void SysTick_Init(){
	SysTick ->CTRL = 5;//We use precision clk
}	