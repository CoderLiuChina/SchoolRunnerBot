/*---  Definition and implementation of queues  ---*/
#include "Queue.h"

/*---  Queue manipulation functions  ---*/

/**
 * @brief Initialize queues and queue pointer groups
 *        During initialization, the first data is set to 0x7F or 127, the next address is NULL, and the pointer group is associated with the corresponding part
 *
 * @param q
 * @param q_pointer
 */
void Queue_Init(Queue *q, Queue_Pointer *q_pointer)
{
    q->data = 0x7F;
    q->next = NULL;
    q_pointer->TOP = q;
    q_pointer->END = q;
}

/**
 * @brief DPush the data into the queue
 *
 * @param q_pointer A pointer group for an associated queue that is used to locate queues
 * @param datapush The data to be passed in
 */
void Queue_Push(Queue_Pointer *q_pointer, uint8_t datapush)
{
    q_pointer->END->next = (struct Queue *)malloc(sizeof(Queue));
    q_pointer->END = (Queue *)q_pointer->END->next;
    q_pointer->END->data = datapush;
}

/**
 * @brief Eject the data at the top of the queue and free up memory space
 *
 * @param q_pointer A pointer group for an associated queue that is used to locate queues
 * @return uint8_t
 */
uint8_t Queue_Pop(Queue_Pointer *q_pointer)
{
    uint8_t datapop;
    if (q_pointer->TOP == q_pointer->END || q_pointer->TOP->data == 127)
    {
        datapop = q_pointer->TOP->data;
        q_pointer->TOP->data = 127;
    }
    else
    {
        datapop = q_pointer->TOP->data;
        Queue *FreeBitCache = q_pointer->TOP;
        q_pointer->TOP = (Queue *)q_pointer->TOP->next;
        free(FreeBitCache);
    }
    return datapop;
}