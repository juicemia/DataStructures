#ifndef STACK_ARR_H
#define STACK_ARR_H

#include "stdlib.h"
#include "stdio.h"

typedef struct stack_arr {
	int array[100];
	int size;
} stack_arr_t;


void stack_push(stack_arr_t *, int);
int stack_pop(stack_arr_t *);
int stack_peek(stack_arr_t *);
int stack_peek_bottom(stack_arr_t *);
void empty_stack(stack_arr_t *);
void copy_stack(stack_arr_t *, stack_arr_t *);
int stack_isEmpty(stack_arr_t *);
int stack_size(stack_arr_t *);

#endif
