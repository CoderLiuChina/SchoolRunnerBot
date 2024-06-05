/* --- Set of All the Variables in Headers --- */

#ifndef _VARIABLES_H_
#define _VARIABLES_H_

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

#endif // !_VARIABLES_H_
