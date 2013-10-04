#ifndef STACK_H
#define STACK_H

#include "doublyLinkedList.h"

typedef struct stack {
	doubly_linked_list_t stack_dll;
} stack_t;

void stack_push(stack_t *, int);
int stack_pop(stack_t *);
int stack_peek(stack_t *);
int stack_peek_bottom(stack_t *);
void empty_stack(stack_t *);
void copy_stack(stack_t *, stack_t *);
int stack_isEmpty(stack_t *);
int stack_size(stack_t *);

#endif
