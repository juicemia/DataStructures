#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include "stdlib.h"
#include "stdio.h"
typedef struct linked_list {
	node_t* first;
	node_t* last;
	int count;
} linked_list_t;

void printList(linked_list_t*);
void addBottom(linked_list_t*, int);
void addTop(linked_list_t*, int);
void removeTop(linked_list_t*);
void removeBottom(linked_list_t*);
void insertAfter(linked_list_t*, int, int);
void insertBefore(linked_list_t*, int, int);
void removeAfter(linked_list_t*, int);
void removeNode(linked_list_t*, int);
int contains(linked_list_t*, int);
void copy(linked_list_t*, linked_list_t*);
void emptyLL(linked_list_t*);
#endif
