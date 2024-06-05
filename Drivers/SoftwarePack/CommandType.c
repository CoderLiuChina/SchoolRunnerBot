/* --- Command compilation and interpretation functions --- */

#include "CommandType.h"


/**
 * @brief Pop the Command from RxQueue, Decode and build a Command struct with data
 * 
 * @param q 
 */
void CommandDecode(Queue_Pointer *q)
{
    Command *ReturnCom = (Command *)malloc(sizeof(Command));
    switch(Queue_Pop(q))
    {
        case 'M':
            ReturnCom->CommandHead = Queue_Pop(q);
            ReturnCom->CommandData = Queue_Pop(q);
            MotorDirectionControl(ReturnCom);
            while (Queue_Pop(q) != 'E'){}
            break;
        default:
            while(Queue_Pop(q)!='E'){}
            break;
    }
    
}