#include "MyGPIO.h"
#include "Mydelay.h"
#include "MyUSART.h"
#include "stm32f10x_tim.h"


TIM_OCInitTypeDef TIM_OCStruct;
TIM_TimeBaseInitTypeDef TIM_BaseStruct;
uint16_t i = 0;

void TM_TIMER_Init(void) {
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
		TIM_BaseStruct.TIM_Prescaler = 1;
    TIM_BaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_BaseStruct.TIM_Period = 3600; /* 10kHz PWM */
    TIM_BaseStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_BaseStruct.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM3, &TIM_BaseStruct);
    TIM_Cmd(TIM3, ENABLE);
}
 
void TM_PWM_Init(void) {
    TIM_OCStruct.TIM_OCMode = TIM_OCMode_PWM2;
    TIM_OCStruct.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCStruct.TIM_OCPolarity = TIM_OCPolarity_Low;
    /* 25% duty cycle 900*/
    /* 50% duty cycle 1800*/
		/* 75% duty cycle 2700*/
    TIM_OCStruct.TIM_Pulse = 0; 
    TIM_OC3Init(TIM3, &TIM_OCStruct);
    TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
    /* 100% duty cycle 3600*/
}

int main(void)
{
	TM_TIMER_Init();
	TM_PWM_Init();
	InitMyGPIO();
	InitMyUSART1();
	sendString(a);
	sendString(StringReceive);
	while(1)
	{
		if(StringReceive[0] != i)
		{
			i = StringReceive[0];
			TIM_OCStruct.TIM_Pulse = i*360; 
			TIM_OC3Init(TIM3, &TIM_OCStruct);
			TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
		}
//		if(StringReceive[0] == 'N')
//		{
//			TIM_OCStruct.TIM_Pulse = 901; 
//			TIM_OC3Init(TIM3, &TIM_OCStruct);
//			TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
//			while(StringReceive[0] == 'N');
//		}
//		if(StringReceive[0] == 'T')
//			{
//			TIM_OCStruct.TIM_Pulse = 1801; 
//			TIM_OC3Init(TIM3, &TIM_OCStruct);
//			TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
//			while(StringReceive[0] == 'T');
//		}
//		if(StringReceive[0] == 'K')
//			{
//			TIM_OCStruct.TIM_Pulse = 2701; 
//			TIM_OC3Init(TIM3, &TIM_OCStruct);
//			TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
//			while(StringReceive[0] == 'K');
//		}
//		if(StringReceive[0] == 'A')
//			{
//			TIM_OCStruct.TIM_Pulse = 3601; 
//			TIM_OC3Init(TIM3, &TIM_OCStruct);
//			TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
//			while(StringReceive[0] == 'A');
//		}
//		if(StringReceive[0] == 'O')
//		{
//			TIM_OCStruct.TIM_Pulse = 'O'; 
//			TIM_OC3Init(TIM3, &TIM_OCStruct);
//			TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
//			while(StringReceive[0] == 'O');
//		}
	};
	return 0;
}


//interrupt.
void USART1_IRQHandler(void)
{
		while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) != RESET)
		{
			element = (char)USART_ReceiveData(USART1);//program usart auto add symbol /0 final string.
		}
		
		if(element ==0x000A)
		{
				while(StringReceive[inde] != 0){
				StringReceive[inde] = 0;
				inde++;
			}
			sendString(StringReceive);
			inde = 0;
			return;
		}
		else{
			StringReceive[inde] = element;
			inde++;
		}
}
