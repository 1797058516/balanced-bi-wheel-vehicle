//
// Created by Administrator on 2022/7/7.
//

#include "TB6612FNG.h"
#include "tim.h"

#include "stm32f1xx_hal_gpio.h"

void TB6612::Init() {
    InitGpio();
    InitPwm();
}

//void TB6612::setMotorModeRight(Mode mode) {
//    switch (mode) {
//
//        case STOP:
//            HAL_GPIO_WritePin(GPIOB,AIN1_Pin,GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(GPIOB,AIN2_Pin,GPIO_PIN_RESET);
//            printf("STOP\r\n");
//        case FORWARD:
//            HAL_GPIO_WritePin(GPIOB,AIN1_Pin,GPIO_PIN_RESET);
//            HAL_GPIO_WritePin(GPIOB,AIN2_Pin,GPIO_PIN_SET);
//            printf("forward\r\n");
//        case BACK:
//            HAL_GPIO_WritePin(GPIOB,AIN1_Pin,GPIO_PIN_SET);
//            HAL_GPIO_WritePin(GPIOB,AIN2_Pin,GPIO_PIN_RESET);
//            printf("back\r\n");
//        }
//    }

//如果用case的话会出现bug
void TB6612::setMotorModeRight(Mode mode) {
    if (mode==STOP) {
        HAL_GPIO_WritePin(GPIOB, AIN1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, AIN2_Pin, GPIO_PIN_RESET);
//        printf("STOP\r\n");
    }
    else if(mode==FORWARD) {
        HAL_GPIO_WritePin(GPIOB, AIN1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, AIN2_Pin, GPIO_PIN_SET);
//        printf("forward\r\n");
    } else if(mode==BACK)
    {
        HAL_GPIO_WritePin(GPIOB,AIN1_Pin,GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB,AIN2_Pin,GPIO_PIN_RESET);
//        printf("back\r\n");
    }
}


void TB6612::setMotorModeLeft(Mode mode) {
    if (mode==STOP) {
        HAL_GPIO_WritePin(GPIOB, BIN1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, BIN2_Pin, GPIO_PIN_RESET);
    }
    else if(mode==FORWARD) {
        HAL_GPIO_WritePin(GPIOB, BIN1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, BIN2_Pin, GPIO_PIN_SET);
    }
    else if (mode==BACK){
            HAL_GPIO_WritePin(GPIOB,BIN1_Pin,GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB,BIN2_Pin,GPIO_PIN_RESET);
    }
}
void TB6612::setMotorPwmRight(float percent) {
    __HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3, timPeriod*percent);
}

void TB6612::setMotorPwmLeft(float percent) {
    int pwmVal=timPeriod*percent;
    __HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_4, pwmVal);
}