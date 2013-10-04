#include "stack_arr.h"

void stack_push(stack_arr_t *st, int val){
	st->array[st->size] = val;
	st->size++; // increment the size of the array	
}
int stack_pop(stack_arr_t *st){	
	// If stack is empty there is nothing to pop
	if (st->size == 0){
		puts("Stack is empty\n");
		return 0;
	}
	
	st->size--; // decrement the size
	return st->array[st->size];
}

int stack_peek(stack_arr_t *st){

	// If stack is empty there is nothing to pop
	if (st->size == 0){
		puts("Stack is empty\n");
		return 0;
	}
	return st->array[st->size - 1];
}
int stack_peek_bottom(stack_arr_t *st){
	if (st->size == 0){
		puts("Stack is empty\n");
		return 0;
	}	
	return st->array[0];
}

void empty_stack(stack_arr_t *st){
	st->size = 0;
}

void copy_stack(stack_arr_t *st, stack_arr_t *target /* Stack to be copied to */){
	int i;
	for(i = 0; i < st->size; i++){
		target->array[i] = st->array[i];
	}
	target->size = st->size;
}

int stack_isEmpty(stack_arr_t *st){
	return st->size == 0 ? 1 : 0;
}
int stack_size(stack_arr_t *st){
	return st->size;
}
