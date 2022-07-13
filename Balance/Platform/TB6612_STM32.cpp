//
// Created by Administrator on 2022/7/7.
//

#include "TB6612_STM32.h"
#include "gpio.h"
#include "tim.h"

//void TB6612::InitGpio() {
//    GPIO_InitTypeDef GPIO_InitStruct = {0};
//
//    /* GPIO Ports Clock Enable */
//    __HAL_RCC_GPIOD_CLK_ENABLE();
//    __HAL_RCC_GPIOA_CLK_ENABLE();
//    __HAL_RCC_GPIOB_CLK_ENABLE();
//
//    /*Configure GPIO pin Output Level */
//    HAL_GPIO_WritePin(GPIOB, BIN2_Pin|BIN1_Pin|AIN1_Pin|AIN2_Pin, GPIO_PIN_RESET);
//
//    /*Configure GPIO pins : PBPin PBPin PBPin PBPin */
//    GPIO_InitStruct.Pin = BIN2_Pin|BIN1_Pin|AIN1_Pin|AIN2_Pin;
//    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//    GPIO_InitStruct.Pull = GPIO_NOPULL;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
//    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//}
//void TB6612::InitPwm() {
//    MX_TIM2_Init();
////    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);
////    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);
//}
//
//void TB6612::setMotorPwmLeft(float percent) {
//    int pwmVal=timPeriod*percent;
//    __HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3, pwmVal);
//}
//
//void TB6612::setMotorPwmRight(float percent) {
//   __HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_4, timPeriod*percent);
//}
//
//void TB6612::setMotorModeLeft(Mode) {
////    switch () {
////        case STOP:
////    }
//    if(STOP){
//
//    }
//    else if(FORWARD){
//        HAL_GPIO_WritePin(GPIOB,AIN1_Pin,GPIO_PIN_RESET);
//        HAL_GPIO_WritePin(GPIOB,AIN2_Pin,GPIO_PIN_SET);
//    }
//    else if(BACK){
//        HAL_GPIO_WritePin(GPIOB,AIN1_Pin,GPIO_PIN_SET);
//        HAL_GPIO_WritePin(GPIOB,AIN2_Pin,GPIO_PIN_RESET);
//    }
//
//}
//void setMotorPwmRight(float percent){
//
//}