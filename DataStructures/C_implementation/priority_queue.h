#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "doublyLinkedList.h"

typedef struct priority_queue {
	doubly_linked_list_t queue_dll;
} p_queue_t;

void queue_enqueue(p_queue_t *, int);
int queue_dequeue(p_queue_t *);
int queue_peek(p_queue_t *);
int queue_peek_bottom(p_queue_t *);
void empty_queue(p_queue_t *);
void copy_queue(p_queue_t *, p_queue_t *);
int queue_isEmpty(p_queue_t *);
int queue_size(p_queue_t *);

#endif
