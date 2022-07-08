//
// Created by Administrator on 2022/7/8.
//

#include "PID.h"

PID::PID(float kp, float ki, float kd, float interval) :isBegin(true),Output(0){
    setPID(kp,ki,kd,interval);
    setOutputLim(-std::numeric_limits<float>::max(), std::numeric_limits<float>::max());
    setTarget(0);
    resetState();
}

void PID::setInterval(float interval) {
    this->Interval=interval;
}

float PID::getInterval() {
    return this->Interval;
}

void PID::setPID(float kp, float ki, float kd) {
    this->kp=kp;
    this->kd=kd*Interval;
    this->ki=ki/Interval;
}

void PID::setPID(float kp, float ki, float kd, float interval) {
    this->Interval=interval;
    this->kp=kp;
    this->kd=kd*interval;
    this->ki=ki/interval;
}

void PID::setOutputLim(float limL, float limH) {
    this->outputLimL=limL;
    this->outputLimH=limH;
}

void PID::setTarget(float target) {
    this->Target=target;
}

float PID::getTarget() const {
    return this->Target;
}

void PID::resetState() {
    errOld=0;
    isBegin=true;
    Output=0;
}



PIDPosition::PIDPosition(float kp, float ki, float kd, float Interval) : PID(kp, ki, kd, Interval) {
    resetState();
}

float PIDPosition::computePid(float feedback) {
    float err;
    err=Target-feedback;

    if(isBegin){
        errOld=err;
        isBegin= false;
    }

    if((Output>outputLimH && Output<outputLimH)||(Output == outputLimH && err<0)||(Output==outputLimL && err>0))
    {
        intergral+=ki*(err +errOld)/2;
    }

    Output=kp*err+intergral+kd*(err-errOld);
    limit<float>(Output,outputLimL,outputLimH);
    errOld=err;
    return Output;
}

void PIDPosition::resetState() {
    intergral=0;
    PID::resetState();
}

