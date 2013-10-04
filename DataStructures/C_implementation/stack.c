#include "stack.h"

void stack_push(stack_t *st, int val){
	addTop(&st->stack_dll, val);
}
int stack_pop(stack_t *st){
	int retVal;
	
	// If stack is empty there is nothing to pop
	if (st->stack_dll.count == 0){
		puts("Stack is empty\n");
		return 0;
	}
	
	retVal = stack_peek(st);
	removeTop(&st->stack_dll);
	return retVal;
}

int stack_peek(stack_t *st){

	// If stack is empty there is nothing to pop
	if (st->stack_dll.count == 0){
		puts("Stack is empty\n");
		return 0;
	}
	return st->stack_dll.first->value;
}
int stack_peek_bottom(stack_t *st){
	if (st->stack_dll.count == 0){
		puts("Stack is empty\n");
		return 0;
	}
	return st->stack_dll.last->value;
}

void empty_stack(stack_t *st){
	emptyDLL(&st->stack_dll);
}

void copy_stack(stack_t *st, stack_t *target /* Stack to be copied to */){
	copy(&st->stack_dll, &target->stack_dll);
}

int stack_isEmpty(stack_t *st){
	return st->stack_dll.count == 0 ? 1 : 0;
}
int stack_size(stack_t *st){
	return st->stack_dll.count;
}
