/*****************************************/
/* Author  :  Ahmed Assaf                */
/* Version :  V01                        */
/* Date    : 26 August 2020              */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"
#include "STK_interface.h"


void Mega(void);

int main(void)
{
	RCC_VoidInitSystemClock();
	RCC_VoidEnableClock(RCC_ABP2, 0);	//AFIO
	RCC_VoidEnableClock(RCC_ABP2, 2);	//GPIO
	
	EXTI_VoidSetCallBack(Mega);				//EXTI CallBack
	
	GPIO_VoidSetPinDirection(GPIOA, PIN0, INPUT_PULL_UP_DOWN);	//pin0 input and pullup resistor
	GPIO_VoidSetPinValue(GPIOA, PIN0, GPIO_HIGH);
	
	GPIO_VoidSetPinDirection(GPIOA, PIN2, OUTPUT_2MHZ_PP);		//pin2 output 2 MHZ
	
	EXTI_VoidInit();
	EXTI_VoidEnableEXTI(LINE0);
	
	NVIC_VoidSetPriority(6, 1, 1, 0x05FA0500);
	NVIC_VoidEnableInterrupt(6);
	while(1);
	return 0;
}

void Mega(void)
{
	GPIO_VoidSetPinValue(GPIOA, PIN2, GPIO_HIGH);
	STK_voidSetBusyWait(1000);
	GPIO_VoidSetPinValue(GPIOA, PIN2, GPIO_LOW);
	STK_voidSetBusyWait(1000);
}