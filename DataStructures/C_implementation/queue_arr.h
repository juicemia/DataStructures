#ifndef QUEUE_ARR_H
#define QUEUE_ARR_H

#include "stdlib.h"
#include "stdio.h"

typedef struct queue_arr {
	int *queue;
	int max_size;
	int size;
	int head;
	int tail;
} queue_arr_t;

void queue_enqueue(queue_arr_t *, int);
int queue_dequeue(queue_arr_t *);
int queue_peek(queue_arr_t *);
int queue_peek_bottom(queue_arr_t *);
void empty_queue(queue_arr_t *);
void copy_queue(queue_arr_t *, queue_arr_t *);
int queue_isEmpty(queue_arr_t *);
int queue_size(queue_arr_t *);

#endif
