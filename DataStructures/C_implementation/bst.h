#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "stdlib.h"
#include "stdio.h"

typedef struct tree_node tree_node_t;

struct tree_node {
	int value;
	tree_node_t *left;
	tree_node_t *right;
};

typedef struct binary_search_tree {
	tree_node_t *root;
	int size;
} bst_t;

void tree_add(bst_t *, int);
void tree_remove(bst_t *, int);
int tree_peek_root(bst_t *);
void empty_tree(bst_t *);
void copy_tree(bst_t *, bst_t *);
int tree_isEmpty(bst_t *);
int tree_size(bst_t *);
void print_tree(bst_t *);
int contains(bst_t *, int);
#endif
