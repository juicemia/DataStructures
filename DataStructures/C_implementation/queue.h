#ifndef QUEUE_H
#define QUEUE_H

#include "doublyLinkedList.h"

typedef struct queue {
	doubly_linked_list_t queue_dll;
} queue_t;

void queue_enqueue(queue_t *, int);
int queue_dequeue(queue_t *);
int queue_peek(queue_t *);
int queue_peek_bottom(queue_t *);
void empty_queue(queue_t *);
void copy_queue(queue_t *, queue_t *);
int queue_isEmpty(queue_t *);
int queue_size(queue_t *);

#endif
