#ifndef __TIM_BASE_H
#define __TIM_BASE_H

#include "stm32f10x.h"

/********************������ʱ��TIM�������壬ֻ��TIM6��7************/
#define BASIC_TIM6 // ���ʹ��TIM7��ע�͵�����꼴��

#ifdef  BASIC_TIM6 // ʹ�û�����ʱ��TIM6
#define            BASIC_TIM                   TIM6
#define            BASIC_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            BASIC_TIM_CLK               RCC_APB1Periph_TIM6
#define            BASIC_TIM_Period            (2-1)               // �պ�1usһ���ж� 
#define            BASIC_TIM_Prescaler         71                     //
#define            BASIC_TIM_IRQ               TIM6_IRQn
#define            BASIC_TIM_IRQHandler        TIM6_IRQHandler

#else  // ʹ�û�����ʱ��TIM7
#define            BASIC_TIM                   TIM7
#define            BASIC_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            BASIC_TIM_CLK               RCC_APB1Periph_TIM7
#define            BASIC_TIM_Period            (1000-1)
#define            BASIC_TIM_Prescaler         71
#define            BASIC_TIM_IRQ               TIM7_IRQn
#define            BASIC_TIM_IRQHandler        TIM7_IRQHandler

#endif
/**************************��������********************************/


void BASIC_TIM_Conf(void);







#endif


