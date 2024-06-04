/* --- Motor Function Header --- */
/* --- Designed by CoderLiuChina from GitHub --- */

#ifndef _MOTOR_H_
#define _MOTOR_H_

#include "main.h"
#include "tim.h"

#define WHEEL_PWM &htim3
#define WHEEL_L_CHANNEL TIM_CHANNEL_1
#define WHEEL_R_CHANNEL TIM_CHANNEL_2

void MotorDirectionControl(char MotorCommandHead, uint8_t speed);

#endif // !_MOTOR_H_
