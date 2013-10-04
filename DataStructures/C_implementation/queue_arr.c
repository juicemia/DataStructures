#include "queue_arr.h"

void queue_enqueue(queue_arr_t *q, int val){
	int *temp;
	int i, j; //counters
	if (q->size == 0){
		q->max_size = 4;
		q->queue = (int *)malloc(sizeof(int) * q->max_size);
		q->head = 0;
		q->tail = -1; // because it will be incremented to 0 next
	}else if (q->size == q->max_size){ //realloc array
		q->max_size = q->max_size * 2;
		temp = (int *)malloc(sizeof(int) * q->max_size);
		
		// check if head is larger than tail
		if (q->head > q->tail){
			for (i = q->head, j = 0; i < q->size; j++, i++){
				temp[j] = q->queue[i];
			}
			for (i = 0; i < q->head; i++, j++){
				temp[j] = q->queue[i];
			}
			
		} else {
			j = 0;
			for(i = q->head; i <= q->tail; i++, j++){
				temp[j] = q->queue[i];
			}
		}
			
		// reset head and tail
		
		q->head = 0;
		q->tail = q->size - 1;
		free(q->queue);//free previously allocated memory
		q->queue = temp;
	}

	q->size++;
	if(q->tail == q->max_size){
		q->tail = 0;
	} else{
		q->tail++;
	}
	q->queue[q->tail] = val;

	
	
}
int queue_dequeue(queue_arr_t *q){
	int retVal; 
	if (q->size == 0){
		puts("Stack is empty\n");
		return 0;
	}
	
	q->size--; // decrement the size
	retVal = queue_peek(q);
	if (q->head == q->max_size - 1){
		q->head = 0;
	} else {
		q->head++;
	}
	return retVal;
}

int queue_peek(queue_arr_t *q){
	if (q->size == 0){
		puts("queue is empty\n");
		return 0;
	}
	return q->queue[q->head];
}
int queue_peek_bottom(queue_arr_t *q){
	if (q->size == 0){
		puts("queue is empty\n");
		return 0;
	}
	return q->queue[q->tail];
}

void empty_queue(queue_arr_t *q){
	q->size = 0;
	q->tail = 0;
	q->head = 0;
	free(q->queue);
}

void copy_queue(queue_arr_t *q, queue_arr_t *target /* queue to be copied to */){
	int i;
	target->queue = (int *)malloc(sizeof(int) * q->max_size);
	for(i = 0; i < q->size; i++){
		target->queue[i] = q->queue[i];
	}
	target->size = q->size;
	target->tail = q->tail;
	target->head = q->head;
}

int queue_isEmpty(queue_arr_t *q){
	return q->size == 0 ? 1 : 0;
}
int queue_size(queue_arr_t *q){
	return q->size;
}
