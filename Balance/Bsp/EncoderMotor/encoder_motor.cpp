//
// Created by Administrator on 2022/7/6.
//
#include "encoder_motor.h"
#include "stm32f1xx_hal.h"
#include "tim.h"

// EncoderMotor::EncoderMotor(GPIO_TypeDef *motorPinA,GPIO_TypeDef *motorPinB,GPIO_TypeDef *motorPinPwm)
// {
//     //HAL_TIM_Encoder_Start(TIMx,TIM_CHANNEL_1 | TIM_CHANNEL_2);
//
// };
long EncoderMotor::getPos() {

    return pos;
}

short EncoderMotor::getPosDiff() {
    return diff;
}

void EncoderMotor::refresh() {
    short tempCNT =(short)__HAL_TIM_GET_COUNTER(&htim4);	  //¶ÁÈ¡±àÂëÆ÷Êý??
    diff=tempCNT-oldcnt;
    oldcnt=tempCNT;
    pos=pos+diff;
}

float EncoderMotor::getPercent() {
    return 0;
}
