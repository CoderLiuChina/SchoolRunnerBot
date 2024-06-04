/* --- Command compilation and interpretation functions --- */

#include "CommandType.h"

void CommandDecode(Queue_Pointer *q)
{
    char ComType = (char)Queue_Pop(q);
    if(ComType==127)
        return;
    switch (ComType)
    {
    case 'M':
        ComType = Queue_Pop(q);
        ComData = Queue_Pop(q);
        MotorDirectionControl(ComType, ComData);
        break;

    default:
        break;
    }
}