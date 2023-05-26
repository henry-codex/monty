#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * struct globals - Global variables for Monty
 * @num: Integer value
 * @flag: Integer value
 * @line: String value
 * @token: String value
 * @opco: Function opcode in Monty
 * @fil: File
 */
typedef struct globals
{
    int num;
    int flag;
    char *line;
    char *token;
    char *opco;
    FILE *fil;
} globals_t;

extern globals_t global;

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer value
 * @prev: Points to the previous element of the stack (or queue)
 * @next: Points to the next element of the stack (or queue)
 *
 * Description: Doubly linked list node structure for stack, queues,
 * LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Opcode and its function
 * @opcode: The opcode
 * @f: Function to handle the opcode
 *
 * Description: Opcode and its function for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void _add(stack_t **stack, unsigned int num_line);
void _push(stack_t **stack, unsigned int num_line);
void _pall(stack_t **stack, unsigned int num_line);
void _verify2(stack_t **stack, unsigned int num_line);
void free_l(stack_t **stack);
void delete_jump(char *line);

#endif /* MONTY_H */

