#include "MyUSART.h"

USART_InitTypeDef TypeUSART;
GPIO_InitTypeDef GPIO_ForUsart;

void InitMyUSART1(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOA, ENABLE);
	
	//TX
	GPIO_ForUsart.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_ForUsart.GPIO_Pin = GPIO_Pin_9;
	GPIO_ForUsart.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_ForUsart);
	
	//RX
	GPIO_ForUsart.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_ForUsart.GPIO_Pin = GPIO_Pin_10;
	GPIO_ForUsart.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_ForUsart);
	
	//init uasrt.
	USART_Cmd(USART1, ENABLE);
	TypeUSART.USART_BaudRate = 9600;
	TypeUSART.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	TypeUSART.USART_Parity = USART_Parity_No;
	TypeUSART.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	TypeUSART.USART_StopBits = USART_StopBits_1;
	TypeUSART.USART_WordLength = USART_WordLength_8b;
	
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	NVIC_EnableIRQ(USART1_IRQn);
	
	USART_Init(USART1, &TypeUSART);
}

void USART1_IRQHandler(void)
{
		while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) != RESET)
		{
			element = (char)USART_ReceiveData(USART1);//program usart auto add symbol /0 final string.
		}
		
		if(element == 0x000A) 
		{
			sendString(StringReceive);
			inde = 0;
			return;
		}
		else{
			StringReceive[inde] = element;
			inde++;
		}
}

void sendString(char *string){
		while(*string != '\0'){
			USART_SendData(USART1, *string);
			 while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
            {
						}
			string++;
		}
}
