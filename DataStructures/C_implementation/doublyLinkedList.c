#include "doublyLinkedList.h"

#define NEXT node->next
#define PREVIOUS node->prev
#define NODE_VAL node->value
#define FIRST list->first
#define LAST list->last

static void addFirst(doubly_linked_list_t*, dl_node_t*);

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

void addTop(doubly_linked_list_t* list, int value){
	dl_node_t *newNode = malloc(sizeof (dl_node_t));
	newNode->value = value;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (list->count == 0){
		// If no items exist in the list
		addFirst(list, newNode);
	} else {
		newNode->next = FIRST;
		FIRST->prev = newNode;
		FIRST = newNode;
	}
	list->count++;
}

void addBottom(doubly_linked_list_t* list, int value){
	dl_node_t *newNode = malloc(sizeof (dl_node_t));
	newNode->value = value;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (list->count == 0){
		// If no items exist in the list
		addFirst(list, newNode);
	} else {
		LAST->next = newNode;
		newNode->prev = LAST; // set the prev node
		LAST = newNode;
	}
	list->count++;
}
void removeTop(doubly_linked_list_t* list){
	if (list->count != 0){
		list->count--;
		dl_node_t *tempNode = FIRST;
		FIRST = tempNode->next;
		if (list->count != 0) FIRST->prev = NULL; // reset the previous node pointer, if it wasn't the last item to be removed
		free(tempNode); // free the removed memory
	}
}
void removeBottom(doubly_linked_list_t* list){
	if (list->count != 0){
		list->count--;
		dl_node_t *node = FIRST;
		dl_node_t *prevNode = node;
		dl_node_t *tempNode;

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
void insertAfter(doubly_linked_list_t* list, int search /* Value to be searched for */, int newVal){
	if (list->count != 0){
		dl_node_t *node = FIRST;
		dl_node_t *newNode = malloc(sizeof (dl_node_t));
		newNode->value = newVal;
		while(node != NULL){
			if (NODE_VAL == search){
				newNode->next = NEXT;
				newNode->prev = node; // assign the previous node
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
void insertBefore(doubly_linked_list_t* list, int search /* Value to be searched for */, int newVal){
	if (list->count != 0){
		dl_node_t *node = FIRST;
		dl_node_t *newNode = malloc(sizeof (dl_node_t));

		newNode->value = newVal;
		if (NODE_VAL == search){ // quick way to check the first value
			addTop(list, newVal);
			return;
		}

		node = NEXT; // since we checked the first one, let's move to the next one

		while(node != NULL){
			if (NODE_VAL == search){
				newNode->next = node;
				newNode->prev = PREVIOUS; //set the previous node
				PREVIOUS->next = newNode;
				list->count++;
				break;
			}
			node = NEXT;
		}
	} else {
		addTop(list, newVal);
	}
}
void removeAfter(doubly_linked_list_t* list, int search /* Value to be searched for */){
	if (list->count != 0){
		dl_node_t *node = FIRST;
		dl_node_t *tempNode;
		while(node != NULL){
			if (NODE_VAL == search){
				tempNode = NEXT;
				if (tempNode != NULL) {
					// The node to be removed exists
					NEXT = tempNode->next;
					if (tempNode->next != NULL)	tempNode->next->prev = node; // if NEXT is null it will not have a prev pointer
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

void removeBefore(doubly_linked_list_t* list, int search /* Value to be searched for */){
	if (list->count != 0){
		dl_node_t *node = FIRST;
		dl_node_t *tempNode;

		if (NODE_VAL == search){ // quick way to check the first value
			// There is no value to be removed before the first one
			return;
		}
		node = NEXT; // since we checked the first one, let's move to the next one

		while(node != NULL){
			if (NODE_VAL == search){
				tempNode = PREVIOUS;
				tempNode->prev->next = node; // said the node before the 'to be removed' node to point to the current node
				PREVIOUS = tempNode->prev;
				free(tempNode);
				list->count--;
				break;
			}
			node = NEXT;
		}
	}
}
void removeNode(doubly_linked_list_t* list, int search /* Value to be searched for */){
	if (list->count != 0){
		dl_node_t *node = FIRST;
		if (NODE_VAL == search){ // checking the first value
			// All we have to do is just remove the top value
			removeTop(list);
			return;
		}
		node = NEXT; // not the first one

		while(node != NULL){
			if (NODE_VAL == search){
				PREVIOUS->next = NEXT; // reset prev node pointer to point to next node
				if (NEXT != NULL) NEXT->prev = PREVIOUS; // if NEXT is null it will not have a prev pointer
				free(node);
				list->count--;
				break;
			}
			node = NEXT;
		}
	}
}
void printList(doubly_linked_list_t* list){
	dl_node_t *node = FIRST;
	int val;
	while(node != NULL){
		val = NODE_VAL;
		printf("%d \n", val);
		node = NEXT;
	}
}

static void addFirst(doubly_linked_list_t* list, dl_node_t* node){
	// This is called on the occasion that the list is empty
	FIRST = node;
	LAST = node;
}

int contains(doubly_linked_list_t* list, int item){
	dl_node_t *node = FIRST;
	while(node != NULL){
		if (NODE_VAL == item) return 1;
		node = NEXT;
	}
	return 0;
}

void copy(doubly_linked_list_t* list, doubly_linked_list_t* target){
	if( list->count !=0){
		// First let's copy the first item
		dl_node_t *newNode = malloc(sizeof (dl_node_t)); // this will hold temporary nodes
		dl_node_t *node;				   // this will hold nodes to the new linked list
		dl_node_t *oldNode = FIRST;		   // this will hold nodes from the old linked list
		int i;					   // counter for loop
		target->first = newNode;
		node = target->first;
		NODE_VAL = oldNode->value;
		PREVIOUS = NULL;
		while(oldNode->next != NULL){
			oldNode = oldNode->next;	// advance the node pointer
			newNode = malloc(sizeof (dl_node_t));	// allocate space for the new node
			NEXT = newNode;
			newNode->prev = node;

			node = NEXT;
			NODE_VAL = oldNode->value;
		}

		target->last = node;
		target->last->next = NULL; // make sure that last doesn't point anywhere

		// copy the count, of course
		target->count = list->count;
	}
}

void emptyDLL(doubly_linked_list_t* list){
	dl_node_t *node = FIRST;
	while(node != NULL){
		free(PREVIOUS);
		node = NEXT;
	}
	free(node); // free the last node
	list->count = 0;
	FIRST = NULL;
	LAST = NULL;
}
