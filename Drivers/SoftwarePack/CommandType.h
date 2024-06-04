/* --- Communication structure of the vehicle --- */
/* --- Encoding and interpretation source code are specified here --- */

#ifndef _COMMANDTYPE_H_
#define _COMMANDTYPE_H_

#include "main.h"

#include "Queue.h"

#include "Motor.h"

extern uint8_t ComData;

/**
 * @brief Command Structure
 *
 * @param CommandHead The first character of the command indicates the purpose of the instruction
 * @param CommandData The command value indicates the variable modification value, target is determined by CommandHead
 */
typedef struct
{
    char CommandHead, CommandData;
} Command;

/* --- Command sending format --- */
/* --- CommandHead(Capital Letter) + CommandData(Integer between 0 and 100, or letters) --- */
/* --- While Decoding, first check the Head, then give the data, read until letter 'E' ---*/
/* --- Example: MF30E -> Command: Move, Status: Forward, Speed: 30 --- */

void CommandDecode(Queue_Pointer *q);

#endif // ! _COMMANDTYPE_H_