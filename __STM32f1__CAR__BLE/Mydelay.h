#include "stm32f10x.h"
#include "stm32f10x_rcc.h"

void delay_ms(int i)
{
	i = i * 8000;
	while(i--){};
}

void delay_s(int i)
{
	i = i * 8000000;
	while(i--){};
}
