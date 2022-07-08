//
// Created by Administrator on 2022/7/6.
//

#ifndef BALANCE_ENCODER_MOTOR_H
#define BALANCE_ENCODER_MOTOR_H
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_tim.h"
typedef enum
{
    Encoder_Motor_Target_Position,
    Encoder_Motor_Target_Speed,
    Encoder_Motor_PID_Disabled
}Encoder_Motor_Target_Typedef;

class EncoderMotor
{
public:

//    EncoderMotor(GPIO_TypeDef *motorPinA,GPIO_TypeDef *motorPinB,
//                 GPIO_TypeDef *motorPinPwm);  不好！！！

    EncoderMotor();

    void Init();

    void refresh();

    long getPos();

    short getPosDiff();

    float getPercent();

    void setSpeed(short spd);

    void setPercent(float p);
private:
    long pos;
    short diff;
    short oldcnt;
};



#endif //BALANCE_ENCODER_MOTOR_H
