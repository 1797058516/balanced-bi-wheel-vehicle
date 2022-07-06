//
// Created by Administrator on 2022/7/6.
//
#include "common_inc.h"

MPU6050 mpu6050(&hi2c1);

void Main(void)
{
    //float a=mpu6050.getAccelXSelfTestFactoryTrim();

    // Init IMU
    do
    {
        mpu6050.Init();
        HAL_Delay(30);
    } while (!mpu6050.testConnection());
    while(1)
    {
        int b=mpu6050.getAccelerationX();
        printf("b:%d\r\n",b);
    }

}