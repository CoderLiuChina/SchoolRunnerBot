/* --- Header of Bluetooth Communication --- */

#ifndef _BLUETOOTH_H_
#define _BLUETOOTH_H_

#include "main.h"

#include "Queue.h"
#include "Variables.h"

#define BLUETOOTH_PORT &huart1

extern uint8_t DataReceiveCache;
extern uint8_t DataReceive;

extern Queue RxQueue;
extern Queue_Pointer RxQueue_Pointer;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void BluetoothInit(UART_HandleTypeDef *huart);

#endif // !_BLUETOOTH_H_