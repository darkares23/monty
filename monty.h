#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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

extern stack_t *head;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @func: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
char *opcode;
void (*func)(stack_t **stack, unsigned int line_number);
} instruction_t;

void (*get_op_func(char *opcode))(stack_t**, unsigned int);
void op_validation(char *buff, char *monty_opcode, int line_number);
void monty_exe(FILE *fd);
void split_str(char *str, int linenum);
int check_mode(stack_t *stack);
int init_stack(stack_t **stack);

/* OP code functions*/
void _push(stack_t **stack, unsigned int linenum);
void _pall(stack_t **stack, unsigned int linenum);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int linenum);
void _swap(stack_t **stack, unsigned int linenum);
void _add(stack_t **stack, unsigned int linenum);
void _nop(stack_t **stack, unsigned int line_number);


/* Error functions*/
int use_err(void);
int malloc_err(void);
int no_int_error(unsigned int lines);
int unknown_op_error(char *opcode, unsigned int line_number);
void open_file_err(char *argv);
int push_err(int linenum);
int pint_err(int linenum);

/*Helpers*/
void free_head(stack_t *head);
void token_free(char **pp);
void stack_free(stack_t **stack);
#endif
