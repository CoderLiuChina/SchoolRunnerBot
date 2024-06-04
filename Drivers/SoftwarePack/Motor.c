/* --- Motor control functions --- */
/* --- Designed by CoderLiuChina from GitHub --- */

#include "Motor.h"

/**
 * @brief Change the direction of movement according to the command
 *        Steering is achieved by means of a motor differential
 *
 * @param MotorCommandHead
 * @param speed
 */
void MotorDirectionControl(char MotorCommandHead, uint8_t speed)
{
    switch (MotorCommandHead)
    {
    case 'F':
        __HAL_TIM_SetCompare(WHEEL_PWM, WHEEL_L_CHANNEL, speed);
        __HAL_TIM_SetCompare(WHEEL_PWM, WHEEL_R_CHANNEL, speed);
        HAL_GPIO_WritePin(AIN1_GPIO_Port, AIN1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(AIN2_GPIO_Port, AIN2_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(BIN1_GPIO_Port, BIN1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(BIN2_GPIO_Port, BIN2_Pin, GPIO_PIN_SET);
        break;

    case 'B':
        __HAL_TIM_SetCompare(WHEEL_PWM, WHEEL_L_CHANNEL, speed);
        __HAL_TIM_SetCompare(WHEEL_PWM, WHEEL_R_CHANNEL, speed);
        HAL_GPIO_WritePin(AIN1_GPIO_Port, AIN1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(AIN2_GPIO_Port, AIN2_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(BIN1_GPIO_Port, BIN1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(BIN2_GPIO_Port, BIN2_Pin, GPIO_PIN_RESET);
        break;

    case 'L':
        __HAL_TIM_SetCompare(WHEEL_PWM, WHEEL_L_CHANNEL, speed);
        __HAL_TIM_SetCompare(WHEEL_PWM, WHEEL_R_CHANNEL, speed / 2);
        HAL_GPIO_WritePin(AIN1_GPIO_Port, AIN1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(AIN2_GPIO_Port, AIN2_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(BIN1_GPIO_Port, BIN1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(BIN2_GPIO_Port, BIN2_Pin, GPIO_PIN_SET);
        break;

    case 'R':
        __HAL_TIM_SetCompare(WHEEL_PWM, WHEEL_L_CHANNEL, speed / 2);
        __HAL_TIM_SetCompare(WHEEL_PWM, WHEEL_R_CHANNEL, speed);
        HAL_GPIO_WritePin(AIN1_GPIO_Port, AIN1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(AIN2_GPIO_Port, AIN2_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(BIN1_GPIO_Port, BIN1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(BIN2_GPIO_Port, BIN2_Pin, GPIO_PIN_SET);
    }
}
