#include "MyGPIO.h"
GPIO_InitTypeDef LED_B0;
GPIO_InitTypeDef LED_B1;
GPIO_InitTypeDef LED_B10;

void TurnOnB0(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_0);
};
void TurnOnB1(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_1);
};
void TurnOnB10(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_10);
};
void TurnOffB0(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_0);
};
void TurnOffB1(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_1);
};
void TurnOffB10(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_10);
};
	
void ToggleB0(void);
void ToggleB1(void);
void ToggleB10(void);

void InitMyGPIO(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	///init B0.
	LED_B0.GPIO_Pin = GPIO_Pin_0;
	LED_B0.GPIO_Mode = GPIO_Mode_Out_OD;
	LED_B0.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB,&LED_B0);
	
	///init B1.
	LED_B1.GPIO_Pin = GPIO_Pin_1;
	LED_B1.GPIO_Mode = GPIO_Mode_Out_OD;
	LED_B1.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB,&LED_B1);
	
	///init B10.
	LED_B10.GPIO_Pin = GPIO_Pin_10;
	LED_B10.GPIO_Mode = GPIO_Mode_Out_OD;
	LED_B10.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB,&LED_B10);
	
	GPIO_Write(GPIOB, 0xffff);
};
