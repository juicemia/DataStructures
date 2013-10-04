#include "priority_queue.h"

void queue_enqueue(p_queue_t *st, int val){
	if (st->size == 0){	
		addBottom(&st->queue_dll, val);	
	}
	else {
		node = st->queue_dll->first;
		
		while (node != NULL && node->value > val){
			node = node->next;
		}
		
		if (node == NULL){
			addBottom(&st->queue_dll, val);
		} else {
			addBefore(&st->queue_dll, node->value, val);
		}
	}

}
int queue_dequeue(p_queue_t *st){
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

int queue_peek(p_queue_t *st){

	// If queue is empty there is nothing to pop
	if (st->queue_dll.count == 0){
		puts("queue is empty\n");
		return 0;
	}
	return st->queue_dll.first->value;
}
int queue_peek_bottom(p_queue_t *st){
	if (st->queue_dll.count == 0){
		puts("queue is empty\n");
		return 0;
	}
	return st->queue_dll.last->value;
}

void empty_queue(p_queue_t *st){
	emptyDLL(&st->queue_dll);
}

void copy_queue(p_queue_t *st, p_queue_t *target /* queue to be copied to */){
	copy(&st->queue_dll, &target->queue_dll);
}

int queue_isEmpty(p_queue_t *st){
	return st->queue_dll.count == 0 ? 1 : 0;
}
int queue_size(p_queue_t *st){
	return st->queue_dll.count;
}
