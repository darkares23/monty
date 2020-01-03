#ifndef MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define DELIMS " \t\n"
#define STACK 0
#define QUEUE 1

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*func)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern char **tokens_op;

int monty_exe(FILE *fd);
char **split_str(char *str, const char *delim);

/* OP code functions*/
void _push(stack_t **stack, unsigned int linenum);
void _pall(stack_t **stack, unsigned int linenum);

/* Error functions*/
int use_err(void);

/*Helpers*/
void myfree(char **pp);
#endif