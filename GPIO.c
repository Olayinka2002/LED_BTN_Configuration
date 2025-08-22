#include "Tm4c123gh6pm.h"
void LED_Init(){
	SYSCTL -> RCGCGPIO |= 0x01; //Port A, pin 4
	GPIOA -> DIR |= 0x10;//We are using pin 4 (10000);
	GPIOA -> DEN |= 0x10;
	GPIOA -> AFSEL &= ~0x10;
	GPIOA -> DATA &= ~ 0x10;
}

void Push_Btn_Init(){
	SYSCTL -> RCGCGPIO |= 0x08;//Port D
	GPIOD -> DEN |= 0x20;//We are using pin 5
	GPIOD -> DIR &=~0x20;//We are setting push_btn as inputs
	GPIOD -> AFSEL &= ~0x20;//No alt function
	GPIOD -> PUR |= 0x20;//pull the pin to 1 when in unknow state, not all mcu have a pull down register
}

uint8_t push_btn_Status(){
	uint8_t data_val = (GPIOD -> DATA & 0x20);
		if(data_val){
				return 0x00;//not pressed
		} else{
				return 0x01;//Pressed
		}
}

void LED_Output(uint8_t btn_status){
	if(btn_status == 0x00){
		GPIOA -> DATA &= ~0x10;
	} else if (btn_status == 0x01){
		GPIOA -> DATA |= 0x10;//turns on the LED
	} else{
		GPIOA -> DATA &= ~0x10;
	}
}