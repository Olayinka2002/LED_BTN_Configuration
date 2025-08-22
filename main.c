#include "GPIO.h"
#include "TM4C123GH6PM.h"

int main(void){
	//Using Polling
	LED_Init();
	Push_Btn_Init();
	while(1){
		uint8_t  status = push_btn_Status();
		LED_Output(status);
	}
}
int main(void){
	
}