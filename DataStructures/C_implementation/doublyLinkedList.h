#ifndef DOUBLE_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H

#include "node.h"
#include "stdlib.h"
#include "stdio.h"
typedef struct doubly_linked_list {
	dl_node_t* first;
	dl_node_t* last;
	int count;
} doubly_linked_list_t;

void printList(doubly_linked_list_t*);
void addBottom(doubly_linked_list_t*, int);
void addTop(doubly_linked_list_t*, int);
void removeTop(doubly_linked_list_t*);
void removeBottom(doubly_linked_list_t*);
void insertAfter(doubly_linked_list_t*, int, int);
void insertBefore(doubly_linked_list_t*, int, int);
void removeAfter(doubly_linked_list_t*, int);
void removeNode(doubly_linked_list_t*, int);
int contains(doubly_linked_list_t*, int);
void copy(doubly_linked_list_t*, doubly_linked_list_t*);
void emptyDLL(doubly_linked_list_t*);
#endif
