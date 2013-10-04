#ifndef NODE_H
#define NODE_H

typedef struct node node_t;
typedef struct doubly_linked_node dl_node_t;

struct node {
	int value;
	node_t* next;
};

struct doubly_linked_node {
	int value;
	dl_node_t* next;
	dl_node_t* prev;
};
#endif
