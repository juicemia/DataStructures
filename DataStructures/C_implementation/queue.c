#include "queue.h"

void queue_enqueue(queue_t *st, int val){
	addBottom(&st->queue_dll, val);
}
int queue_dequeue(queue_t *st){
	int retVal;
	
	// If queue is empty there is nothing to pop
	if (st->queue_dll.count == 0){
		puts("queue is empty\n");
		return 0;
	}
	
	retVal = queue_peek(st);
	removeTop(&st->queue_dll);
	return retVal;
}

int queue_peek(queue_t *st){

	// If queue is empty there is nothing to pop
	if (st->queue_dll.count == 0){
		puts("queue is empty\n");
		return 0;
	}
	return st->queue_dll.first->value;
}
int queue_peek_bottom(queue_t *st){
	if (st->queue_dll.count == 0){
		puts("queue is empty\n");
		return 0;
	}
	return st->queue_dll.last->value;
}

void empty_queue(queue_t *st){
	emptyDLL(&st->queue_dll);
}

void copy_queue(queue_t *st, queue_t *target /* queue to be copied to */){
	copy(&st->queue_dll, &target->queue_dll);
}

int queue_isEmpty(queue_t *st){
	return st->queue_dll.count == 0 ? 1 : 0;
}
int queue_size(queue_t *st){
	return st->queue_dll.count;
}
