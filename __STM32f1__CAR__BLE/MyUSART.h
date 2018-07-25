#include "stm32f10x_usart.h"

static char a[100] = "N\0";
static char StringReceive[100] = "123456789";

static char element;
static int inde = 0;

void sendString(char *string);
void InitMyUSART1(void);