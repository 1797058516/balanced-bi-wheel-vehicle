//
// Created by Administrator on 2022/7/8.
//

#ifndef BALANCE_PID_H
#define BALANCE_PID_H
#include "myMath.h"
#include <limits>
class PID
{
protected:
    bool isBegin;
    float kp,ki,kd;
    float Interval;
    float outputLimL,outputLimH;
    float Target;
    float Output;
    float errOld;
public:
    explicit PID(float kp =0,float ki = 0,float kd = 0,float interval=0.01);

    void setInterval(float interval);
    float getInterval();

    void setPID(float kp,float ki,float kd);
    void setPID(float kp,float ki,float kd,float interval);
    //void setBasic(float kp, float ki, float kd, float interval); 不好
    void getPID();

    void setTarget(float target);
    float getTarget() const;

    void setOutputLim(float limL,float limH);

    virtual void resetState();

    virtual float computePid(float feedback) = 0;

};
//普通梯形积分PID基类
class PIDPosition:public PID{
protected:
    float intergral;
public:
    explicit PIDPosition(float kp=0,float ki=0,float kd=0,float Interval=0.01);
    float computePid(float feedback) override;
    void resetState() override;
};


#endif //BALANCE_PID_H
