#include "linkedList.h"

#define NEXT node->next
#define NODE_VAL node->value
#define FIRST list->first
#define LAST list->last

static void addFirst(linked_list_t*, node_t*);

/*
	Many functions have `if (list->count != 0)`. This is to make sure that the
	linked list is not empty, as removing elements from, or traversing the list that doesn't
	have any elements is pointless.
*/
/*
	`*prevNode` used in many functions signifies the previous node, whereas
	`*tempNode` signifies the node that will be removed, and it is needed
	for the memory to be released by `free()`
*/

void addTop(linked_list_t* list, int value){
	node_t *newNode = malloc(sizeof (node_t));
	newNode->value = value;
	newNode->next = NULL;

	if (list->count == 0){
		// If no items exist in the list
		addFirst(list, newNode);
	} else {
		newNode->next = FIRST;
		FIRST = newNode;
	}
	list->count++;
}

void addBottom(linked_list_t* list, int value){
	node_t *newNode = malloc(sizeof (node_t));
	newNode->value = value;
	newNode->next = NULL;
	if (list->count == 0){
		// If no items exist in the list
		addFirst(list, newNode);
	} else {
		LAST->next = newNode;
		LAST = newNode;
	}
	list->count++;
}
void removeTop(linked_list_t* list){
	if (list->count != 0){
		list->count--;
		node_t *tempNode = FIRST;
		FIRST = FIRST->next;
		free(tempNode); // free the removed memory
	}
}
void removeBottom(linked_list_t* list){
	if (list->count != 0){
		list->count--;
		node_t *node = FIRST;
		node_t *prevNode = node;
		node_t *tempNode;

		// loop reassigns all the nodes but the last one
		while(NEXT != NULL){
			prevNode = node;
			node = NEXT;
		}
		tempNode = node; //the last node
		free(tempNode); // free memory
		if (list->count != 0){ // needed since the count is decremented at the very beginning
			prevNode->next = NULL;
			LAST = prevNode;
		} else{
			// Last element to be deleted
			LAST = NULL;
			FIRST = NULL;
		}
	}
}
void insertAfter(linked_list_t* list, int search /* Value to be searched for */, int newVal){
	if (list->count != 0){
		node_t *node = FIRST;
		node_t *newNode = malloc(sizeof (node_t));
		newNode->value = newVal;
		while(node != NULL){
			if (NODE_VAL == search){
				newNode->next = NEXT;
				NEXT = newNode;
				list->count++;
				break;
			}
			node = NEXT;
		}
	} else {
		addTop(list, newVal);
	}
}
void insertBefore(linked_list_t* list, int search /* Value to be searched for */, int newVal){
	if (list->count != 0){
		node_t *node = FIRST;
		node_t *prevNode = node;
		node_t *newNode = malloc(sizeof (node_t));
		newNode->value = newVal;
		if (NODE_VAL == search){ // quick way to check the first value
			addTop(list, newVal);
			return;
		}
		node = NEXT; // since we checked the first one, let's move to the next one

		while(node != NULL){
			if (NODE_VAL == search){
				newNode->next = node;
				prevNode->next = newNode;
				list->count++;
				break;
			}
			prevNode = node;
			node = NEXT;
		}
	} else {
		addTop(list, newVal);
	}
}
void removeAfter(linked_list_t* list, int search /* Value to be searched for */){
	if (list->count != 0){
		node_t *node = FIRST;
		node_t *tempNode;
		while(node != NULL){
			if (NODE_VAL == search){
				tempNode = NEXT;
				if (tempNode != NULL) {
					// The node to be removed exists
					NEXT = tempNode->next;
					free(tempNode);
					list->count--;
				}
				// If the node to be removed doesn't exist, do nothing
				break;
			}
			node = NEXT;
		}
	}
}

void removeBefore(linked_list_t* list, int search /* Value to be searched for */){
	if (list->count != 0){
		node_t *node = FIRST;
		node_t *tempNode;
		node_t *prevNode = node;
		node_t *prevPrevNode = node; // the node before the previous node

		if (NODE_VAL == search){ // quick way to check the first value
			// There is no value to be removed before the first one
			return;
		}
		node = NEXT; // since we checked the first one, let's move to the next one
		if (NODE_VAL == search){ // checking the second value
			// All we have to do is just remove the top value
			removeTop(list);
			return;
		}
		prevNode = node;
		node = NEXT; // not first two; move on

		while(node != NULL){
			if (NODE_VAL == search){
				tempNode = prevNode;
				prevPrevNode->next = node; // said the node before the 'to be removed' node to point to the current node
				free(tempNode);
				list->count--;
				break;
			}

			prevPrevNode = prevNode;
			prevNode = node;
			node = NEXT;
		}
	}
}
void removeNode(linked_list_t* list, int search /* Value to be searched for */){
	if (list->count != 0){
		node_t *node = FIRST;
		node_t *prevNode = node;
		if (NODE_VAL == search){ // checking the first value
			// All we have to do is just remove the top value
			removeTop(list);
			return;
		}
		node = NEXT; // not the first one

		while(node != NULL){
			if (NODE_VAL == search){
				prevNode->next = NEXT; // reset prev node pointer to point to next node
				free(node);
				list->count--;
				break;
			}

			prevNode = node;
			node = NEXT;
		}
	}
}
void printList(linked_list_t* list){
	node_t *node = FIRST;
	int val;
	while(node != NULL){
		val = NODE_VAL;
		printf("%d \n", val);
		node = NEXT;
	}
}

static void addFirst(linked_list_t* list, node_t* node){
	// This is called on the occasion that the list is empty
	FIRST = node;
	LAST = node;
}

int contains(linked_list_t* list, int item){
	node_t *node = FIRST;
	while(node != NULL){
		if (NODE_VAL == item) return 1;
		node = NEXT;
	}
	return 0;
}

void copy(linked_list_t* list, linked_list_t* target){
	if( list->count !=0){
		// First let's copy the first item
		node_t *newNode = malloc(sizeof (node_t)); // this will hold temporary nodes
		node_t *node;				   // this will hold nodes to the new linked list
		node_t *oldNode = FIRST;		   // this will hold nodes from the old linked list
		int i;					   // counter for loop
		target->first = newNode;
		node = target->first;
		NODE_VAL = oldNode->value;
		for(i = 1; i<list->count && oldNode->next != NULL; i++){
			oldNode = oldNode->next;
			newNode = malloc(sizeof (node_t));
			NEXT = newNode;
			node = NEXT;
			NODE_VAL = oldNode->value;
		}
		target->last = node;
		target->last->next = NULL; // make sure that last doesn't point anywhere

		// copy the count, of course
		target->count = list->count;
	}
}

void emptyLL(linked_list_t* list){
	node_t *node = FIRST;
	node_t *prevNode = FIRST;
	while(node != NULL){
		prevNode = node;
		node = NEXT;
		free(prevNode);
	}
	free(node); // free the last node
	list->count = 0;
	FIRST = NULL;
	LAST = NULL;
}
