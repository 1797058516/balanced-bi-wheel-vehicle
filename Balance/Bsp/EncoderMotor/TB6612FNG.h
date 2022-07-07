//
// Created by Administrator on 2022/7/7.
//

#ifndef BALANCE_TB6612FNG_H
#define BALANCE_TB6612FNG_H
#include <cstdint>

class TB6612
{
public:
    explicit  TB6612()=default;
    enum Mode{
        FORWARD,
        BACK,
        STOP
    };
    Mode mode;
    void Init();
    void InitGpio();
    void InitPwm();

    void setMotorModeLeft(Mode mode);
    void setMotorModeRight(Mode mode);

    void setMotorPwmLeft(float percent);
    void setMotorPwmRight(float percent);
private:
    int timPeriod=1000;



};

#endif //BALANCE_TB6612FNG_H
