#include <stdio.h>
#include "stm32f7xx.h"

/*
********************************************
					BLINK LEDS STM32F746ZG
********************************************
*/


int main(void){
	
	
	RCC->AHB1ENR |= (1UL<<1); // CLOCK PB
	
	/*
	
	GPIOB
	
	*PB0	OUTPUT	MEDIUM SPEED	PULL DOWN
	*PB7	OUTPUT	MEDIUM SPEED	PULL DOWN
	*PB14	OUTPUT	MEDIUM SPEED	PULL DOWN
	
	*/
	
	GPIOB->MODER |= (1UL<<0*2) | (1UL<<7*2) | (1UL<<14*2);
	GPIOB->OTYPER = 0;
	GPIOB->OSPEEDR |= (1UL<<0*2) | (1UL<<7*2) | (1UL<<14*2);
	GPIOB->PUPDR |= (2UL<<0*2) | (2UL<<7*2) | (2UL<<14*2);
	
	/*
		100 ms T = 10 Hz
	*/
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock/10); 
	

	while(true){
	
		
	
	}
}

extern "C"{

	void SysTick_Handler(void){
		
		GPIOB->ODR ^=(1UL<<0);
		GPIOB->ODR ^=(1UL<<7);
		GPIOB->ODR ^=(1UL<<14);
	}
}
