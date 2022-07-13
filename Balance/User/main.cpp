//
// Created by Administrator on 2022/7/6.
//
#include "common_inc.h"
#include "TB6612FNG.h"
#include "stm32f1xx_hal_gpio.h"
#include "PID.h"
#include "../../Bsp/MPU6050/mpu6050.h"
//MPU6050 mpu6050(&hi2c1);
TB6612 tb6612;
PIDPosition leftpid(15,0,0.5,0.01);
PIDPosition rightpid(20,0,0.6,0.01);

void Main(void)
{
    int leftOutput,rightOutput;

    //tb6612.setMotorModeRight(TB6612::BACK);
    leftpid.setTarget(5);
    rightpid.setTarget(5);
    leftpid.setOutputLim(90,800);
    rightpid.setOutputLim(90,800);

    while(1)
    {
        Read_DMP();
        leftOutput=leftpid.computePid(Roll);
        rightOutput=rightpid.computePid(Roll);
        printf("roll:%f\r\n",Roll);
        //printf("gyro:%f\r\n",gyro[0]);
        //printf("%d\r\n",ch1);
       // printf("b:%f\r\n",gx);
        //printf("raw:%f\r\n",ypr[1]* 180/M_PI);
 //       tb6612.setMotorModeLeft(TB6612::BACK);
        tb6612.setMotorPwmLeft(leftOutput);
//        tb6612.setMotorModeRight(TB6612::STOP);
        tb6612.setMotorPwmRight(rightOutput);
        HAL_Delay(10);
//        tb6612.setMotorPwmRight((float )0.15);

    }

}