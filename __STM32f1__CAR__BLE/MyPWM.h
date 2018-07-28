#include "stm32f10x_tim.h"
#include "MyGPIO.h"

static GPIO_InitTypeDef PWM_DongCo_Trai;
static GPIO_InitTypeDef PWM_DongCo_Phai;
static GPIO_InitTypeDef PWM_Servo;

static TIM_OCInitTypeDef TIM_OCStruct;
static TIM_TimeBaseInitTypeDef TIM_BaseStruct;
void InitMyGPIO_PWM(void);

void InitMyTIMER(void);
void InitMyPWM(void);

void SetDongCoTrai(uint16_t *DongCoTrai);
void SetDongCoPhai(uint16_t *DongCoPhai);
void SetServo(uint16_t *Servo);
