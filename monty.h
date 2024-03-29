#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <ctype.h>
#include <limits.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int check_num(char *opcode);
void get_code(FILE *stream, stack_t **stack);
void free_stack(stack_t *stack);
void _push(char *opcode, stack_t **top_stack, unsigned int line);
void _pall(stack_t **sstack, unsigned int __attribute__((unused)) line);
void get_opc(char *opcode, stack_t **cp_stack, unsigned int line);
void _pint(stack_t **stack, unsigned int line);
void _pop(stack_t **stack, unsigned int line);
void _nop(stack_t **stack, unsigned int line);
void _swap(stack_t **stack, unsigned int line);
void _add(stack_t **stack, unsigned int line);

#endif
