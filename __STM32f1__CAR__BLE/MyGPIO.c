#include "MyGPIO.h"
GPIO_InitTypeDef LED_B0;
GPIO_InitTypeDef LED_B1;
GPIO_InitTypeDef LED_B10;
GPIO_InitTypeDef PWM_IN1;
GPIO_InitTypeDef PWM_IN2;
GPIO_InitTypeDef PWM_IN3;
GPIO_InitTypeDef PWM_IN4;

void TurnOnPWM_IN1(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_0);
}

void TurnOffPWM_IN1(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_0);
}
void TurnOnPWM_IN2(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_4);
}

void TurnOffPWM_IN2(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_4);
}

void TurnOnPWM_IN3(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_5);
}

void TurnOffPWM_IN3(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_5);
}

void TurnOnPWM_IN4(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_6);
}

void TurnOffPWM_IN4(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_6);
}


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

void InitMyGPIO_PWM_IN(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	PWM_IN1.GPIO_Pin = GPIO_Pin_0;
	PWM_IN1.GPIO_Mode = GPIO_Mode_Out_PP;
	PWM_IN1.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOA, &PWM_IN1);
	
	PWM_IN2.GPIO_Pin = GPIO_Pin_4;
	PWM_IN2.GPIO_Mode = GPIO_Mode_Out_PP;
	PWM_IN2.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOA, &PWM_IN2);
	
	PWM_IN3.GPIO_Pin = GPIO_Pin_5;
	PWM_IN3.GPIO_Mode = GPIO_Mode_Out_PP;
	PWM_IN3.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOA, &PWM_IN3);
	
	PWM_IN4.GPIO_Pin = GPIO_Pin_6;
	PWM_IN4.GPIO_Mode = GPIO_Mode_Out_PP;
	PWM_IN4.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOA, &PWM_IN4);
	
	GPIO_Write(GPIOA, 0x0000);
}


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
	
	GPIO_Write(GPIOB, 0x0000);
};
