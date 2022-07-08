//
// Created by Administrator on 2022/7/8.
//

#ifndef BALANCE_MYMATH_H
#define BALANCE_MYMATH_H

template<typename T>
void limitLow(T &num,T limL){
    if (num<limL)
    {
        num=limL;
    }
}
template<typename T>
void limitHigh(T &num,T limH){
    if (num>limH)
    {
        num=limH;
    }
}

template<typename T>
void limit(T &num,T limL,T limH){
    limitLow(num,limL);
    limitHigh(num,limH);
}

#endif //BALANCE_MYMATH_H
