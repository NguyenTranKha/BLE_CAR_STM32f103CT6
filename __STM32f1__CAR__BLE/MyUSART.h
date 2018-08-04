#include "stm32f10x_usart.h"

static char a[100] = "N\0";
static char StringReceive[100] = {20,20};
static USART_InitTypeDef TypeUSART;
static GPIO_InitTypeDef GPIO_ForUsart;
static char element;
static int inde = 0;

void sendString(char *string);
void InitMyUSART1(void);
void getStringReceive(char *DongCo, char *servo, char *Buzz);