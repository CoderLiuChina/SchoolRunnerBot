/* --- Functions of Bluetooth Communication --- */

#include "BlueTooth.h"

/**
 * @brief UART callback function, push the data into RxQueue waiting for load
 * 
 * @param huart Pointer of the UART structure
 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    DataReceive = DataReceiveCache;
    Queue_Push(&RxQueue_Pointer, DataReceive);
    HAL_UART_Receive_IT(huart, &DataReceiveCache, sizeof(uint8_t));
}

/**
 * @brief Initialize Bluetooth port
 * 
 * @param huart 
 */
void BluetoothInit(UART_HandleTypeDef *huart)
{
    HAL_UART_Receive_IT(huart, &DataReceiveCache, sizeof(uint8_t));
}