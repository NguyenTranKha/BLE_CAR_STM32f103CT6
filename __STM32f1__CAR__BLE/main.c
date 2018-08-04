#include "MyGPIO.h"
#include "Mydelay.h"
#include "MyUSART.h"
#include "MyPWM.h"

static uint16_t GiaTriDongCoTrai = 0;
static uint16_t GiaTriDongCoPhai = 0;
static uint16_t GiaTriServo = 1450;
static uint16_t FlagDongCo = 20;
static uint16_t FlagServo = 20;
char GiaTriDongCoNhanDuoc;
char GiaTriServoNhanDuoc;
char Buzz;

int main(void)
{
	InitMyGPIO_PWM_IN();
	InitMyGPIO_PWM();
	InitMyTIMER();
	InitMyPWM();
	InitMyGPIO();
	InitMyUSART1();
	//sendString(a);
	//sendString(StringReceive);
	SetServo(&GiaTriServo);
	SetDongCoTrai(&GiaTriDongCoTrai);
	SetDongCoPhai(&GiaTriDongCoPhai);
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
					TurnOnPWM_IN1();
					TurnOffPWM_IN2();
					TurnOnPWM_IN3();
					TurnOffPWM_IN4();
					GiaTriDongCoTrai = (FlagDongCo - 30)*1011;//nhan voi 10% gia tri
					GiaTriDongCoPhai = (FlagDongCo - 30)*1011;
				}
				if(FlagDongCo < 30){
					TurnOffPWM_IN1();
					TurnOnPWM_IN2();
					TurnOffPWM_IN3();
					TurnOnPWM_IN4();
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
					GiaTriServo = 1450 + (FlagServo - 30)*20; //tinh gia tri servo
				}
				if(FlagServo < 30){
					GiaTriServo = 1450 - (30 - FlagServo)*20; //timj gia tri servo
				}
				SetServo(&GiaTriServo);
			}
		}
	};
	return 0;
}
