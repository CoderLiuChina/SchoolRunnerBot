/*---  Header of Queue  ---*/
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "main.h"

#include <stdlib.h>

/*---  Definition of Queue  ---*/

/**
 * @brief Queue definition
 *
 * @param data Information stored in queue bits
 * @param next A pointer of Queue, stores the next address of the queue
 */

typedef struct
{
    uint8_t data;
    struct Queue *next;
} Queue;

/**
 * @brief Queue endpoint pointer definition
 *
 * @param TOP The address at the top of the queue
 * @param END The address at the end of the queue
 * @param QueueBody The queue that corresponds to the pointer group
 */
typedef struct
{
    Queue *TOP;
    Queue *END;
} Queue_Pointer;

/*---  Operate Functions  ---*/
void Queue_Init(Queue *, Queue_Pointer *);
void Queue_Push(Queue_Pointer *, uint8_t);
uint8_t Queue_Pop(Queue_Pointer *);

#endif /*_QUEUE_H_*/