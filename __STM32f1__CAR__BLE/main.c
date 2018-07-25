#include "MyGPIO.h"
#include "Mydelay.h"
#include "MyUSART.h"

int main(void)
{
	InitMyGPIO();
	InitMyUSART1();
	sendString(a);
	sendString(StringReceive);
	while(1)
	{
		delay_ms(1000);
		sendString(StringReceive);
	};
	return 0;
}

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
