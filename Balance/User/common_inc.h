#ifndef LOOP_H
#define LOOP_H

#ifdef __cplusplus
extern "C" {
#endif
/*---------------------------- C Scope ---------------------------*/
#include "stdint-gcc.h"
#include "stm32f1xx_hal.h"
#include "../Core/Inc/i2c.h"
#include "../Inc/main.h"
#include "../Platform/retarget.h"

void Main();

#ifdef __cplusplus
}
/*---------------------------- C++ Scope ---------------------------*/
#include <cstdio>

#include "TB6612_STM32.h"


#endif
#endif