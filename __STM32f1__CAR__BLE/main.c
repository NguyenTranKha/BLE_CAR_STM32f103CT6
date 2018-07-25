#include "MyGPIO.h"
#include "Mydelay.h"
#include "MyUSART.h"

int main(void)
{
	InitMyGPIO();
	InitMyUSART1();
	sendString(a);
	while(1);
	return 0;
}


