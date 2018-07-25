#include "stm32f10x_usart.h"

static char a[100] = "KhaTranNguyen\0";
static char StringReceive[100];

static char element;
static int inde = 0;

void sendString(char *string);
void InitMyUSART1(void);
