#include "MyGPIO.h"
#include "Mydelay.h"
#include "MyUSART.h"
#include "MyPWM.h"

static uint16_t GiaTriDongCoTrai;
static uint16_t GiaTriDongCoPhai;
static uint16_t GiaTriServo = 1500;
static uint16_t FlagDongCo = 0;
static uint16_t FlagServo = 0;
char GiaTriDongCoNhanDuoc;
char GiaTriServoNhanDuoc;
char Buzz;

int main(void)
{
	InitMyGPIO_PWM();
	InitMyTIMER();
	InitMyPWM();
	InitMyGPIO();
	InitMyUSART1();
	sendString(a);
	sendString(StringReceive);
	while(1)
	{
		getStringReceive(&GiaTriDongCoNhanDuoc, &GiaTriServoNhanDuoc, &Buzz);
		if(Buzz == 65) TurnOffB0(); else TurnOnB0();
		if(GiaTriDongCoNhanDuoc != FlagDongCo | GiaTriServoNhanDuoc != FlagServo)
		{
			if(GiaTriDongCoNhanDuoc != FlagDongCo )
			{
				FlagDongCo = GiaTriDongCoNhanDuoc;
				if(FlagDongCo >= 30){
					GiaTriDongCoTrai = (FlagDongCo - 30)*1011;//nhan voi 10% gia tri
					GiaTriDongCoPhai = (FlagDongCo - 30)*1011;
				}
				if(FlagDongCo <= 30){
					GiaTriDongCoTrai = (30 - FlagDongCo)*1011;//nhan voi 10% gia tri
					GiaTriDongCoPhai = (30 - FlagDongCo)*1011;
				}
				SetDongCoTrai(&GiaTriDongCoTrai);
				SetDongCoPhai(&GiaTriDongCoPhai);
			}
			if(GiaTriServoNhanDuoc != FlagServo)
			{
				FlagServo = GiaTriServoNhanDuoc;
				if(FlagServo >= 30){
					GiaTriServo = GiaTriServo + (FlagServo - 30)*50; //tinh gia tri servo
				}
				if(FlagServo <= 30){
					GiaTriServo = GiaTriServo + (30 - FlagServo)*50*(-1); //timj gia tri servo
				}
				SetServo(&GiaTriServo);
			}
			
			USART_SendData(USART1, GiaTriDongCoTrai);
		}
	};
	return 0;
}
