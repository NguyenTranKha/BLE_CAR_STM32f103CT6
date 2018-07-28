#include "MyPWM.h"

void InitMyGPIO_PWM(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	///init B0.
	PWM_DongCo_Trai.GPIO_Pin = GPIO_Pin_1;
	PWM_DongCo_Trai.GPIO_Mode = GPIO_Mode_AF_OD;
	PWM_DongCo_Trai.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOA,&PWM_DongCo_Trai);
	
	///init B1.
	PWM_DongCo_Phai.GPIO_Pin = GPIO_Pin_2;
	PWM_DongCo_Phai.GPIO_Mode = GPIO_Mode_AF_OD;
	PWM_DongCo_Phai.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOA,&PWM_DongCo_Phai);
	
	///init B10.
	PWM_Servo.GPIO_Pin = GPIO_Pin_3;
	PWM_Servo.GPIO_Mode = GPIO_Mode_AF_OD;
	PWM_Servo.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOA,&PWM_Servo);
	
	GPIO_Write(GPIOA, 0xffff);
};

void InitMyTIMER(void) {
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
		TIM_BaseStruct.TIM_Prescaler = 72;
    TIM_BaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_BaseStruct.TIM_Period = 10102; /* 100Hz PWM */
    TIM_BaseStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_BaseStruct.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2, &TIM_BaseStruct);
    TIM_Cmd(TIM2, ENABLE);
}
 
void InitMyPWM(void) {
    TIM_OCStruct.TIM_OCMode = TIM_OCMode_PWM2;
    TIM_OCStruct.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCStruct.TIM_OCPolarity = TIM_OCPolarity_Low;
    
	  TIM_OCStruct.TIM_Pulse = 0; 
    TIM_OC2Init(TIM2, &TIM_OCStruct); //Dong co 1
    TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);
	
    TIM_OCStruct.TIM_Pulse = 0; 
    TIM_OC3Init(TIM2, &TIM_OCStruct); //Dong co 2
    TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);
	
		TIM_OCStruct.TIM_Pulse = 0; 
    TIM_OC4Init(TIM2, &TIM_OCStruct); //servo
    TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);
}

void SetDongCoTrai(uint16_t *DongCoTrai)
{
	TIM_OCStruct.TIM_Pulse = *DongCoTrai;
	TIM_OC2Init(TIM2, &TIM_OCStruct);
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);
};

void SetDongCoPhai(uint16_t *DongCoPhai)
{
	TIM_OCStruct.TIM_Pulse = *DongCoPhai;
	TIM_OC3Init(TIM2, &TIM_OCStruct);
	TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);
};

void SetServo(uint16_t *Servo)
{
	TIM_OCStruct.TIM_Pulse = *Servo;
	TIM_OC4Init(TIM2, &TIM_OCStruct);
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);
};