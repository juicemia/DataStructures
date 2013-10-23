#ifndef HEAP
#define HEAP

#include "bst.h"

typedef bst_t heap_t; // heap is essentially just a binary tree

// virtually will have all the identical methods from binary tree
void heap_add(heap_t *, int);
void heap_remove(heap_t *, int);
int heap_peek_top(heap_t *);
void empty_heap(heap_t *);
void copy_heap(heap_t *, heap_t *);
int heap_isEmpty(heap_t *);
int heap_size(heap_t *);
void print_heap(heap_t *);
int contains_heap(heap_t *, int);

#endif
