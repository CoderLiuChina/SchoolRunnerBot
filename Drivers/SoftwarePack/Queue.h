/*---  Header of Queue  ---*/
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "main.h"

#include <stdlib.h>
#include "Variables.h"

/*---  Definition of Queue  ---*/







/*---  Operate Functions  ---*/
void Queue_Init(Queue *, Queue_Pointer *);
void Queue_Push(Queue_Pointer *, uint8_t);
uint8_t Queue_Pop(Queue_Pointer *);

#endif /*_QUEUE_H_*/