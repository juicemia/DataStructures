#include "doublyLinkedList.h"

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
		newNode->next = list->first;
		list->first->prev = newNode;
		list->first = newNode;	
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
		list->last->next = newNode;
		newNode->prev = list->last; // set the prev node
		list->last = newNode;	
	}
	list->count++;
}
void removeTop(doubly_linked_list_t* list){
	if (list->count != 0){
		list->count--;
		dl_node_t *tempNode = list->first;
		list->first = tempNode->next;
		if (list->count != 0) list->first->prev = NULL; // reset the previous node pointer, if it wasn't the last item to be removed
		free(tempNode); // free the removed memory
	}
}
void removeBottom(doubly_linked_list_t* list){
	if (list->count != 0){	
		list->count--;
		dl_node_t *node = list->first;
		dl_node_t *prevNode = node;
		dl_node_t *tempNode;	
		
		// loop reassigns all the nodes but the last one
		while(node->next != NULL){
			prevNode = node;
			node = node->next;
		}
		tempNode = node; //the last node
		free(tempNode); // free memory
		if (list->count != 0){ // needed since the count is decremented at the very beginning
			prevNode->next = NULL;
			list->last = prevNode;
		} else{
			// Last element to be deleted
			list->last = NULL;
			list->first = NULL;
		}
	}
}
void insertAfter(doubly_linked_list_t* list, int search /* Value to be searched for */, int newVal){
	if (list->count != 0){
		dl_node_t *node = list->first;
		dl_node_t *newNode = malloc(sizeof (dl_node_t));
		newNode->value = newVal;
		while(node != NULL){
			if (node->value == search){
				newNode->next = node->next;
				newNode->prev = node; // assign the previous node
				node->next = newNode;
				list->count++;
				break;
			}
			node = node->next;
		}
	} else {
		addTop(list, newVal);
	}
}
void insertBefore(doubly_linked_list_t* list, int search /* Value to be searched for */, int newVal){
	if (list->count != 0){
		dl_node_t *node = list->first;
		dl_node_t *newNode = malloc(sizeof (dl_node_t));

		newNode->value = newVal;
		if (node->value == search){ // quick way to check the first value
			addTop(list, newVal);
			return;
		}

		node = node->next; // since we checked the first one, let's move to the next one

		while(node != NULL){
			if (node->value == search){
				newNode->next = node;
				newNode->prev = node->prev; //set the previous node
				node->prev->next = newNode;
				list->count++;
				break;
			}
			node = node->next;
		}
	} else {
		addTop(list, newVal);
	}
}
void removeAfter(doubly_linked_list_t* list, int search /* Value to be searched for */){
	if (list->count != 0){
		dl_node_t *node = list->first;
		dl_node_t *tempNode;
		while(node != NULL){
			if (node->value == search){
				tempNode = node->next;
				if (tempNode != NULL) {
					// The node to be removed exists
					node->next = tempNode->next;
					if (tempNode->next != NULL)	tempNode->next->prev = node; // if node->next is null it will not have a prev pointer
					free(tempNode);
					list->count--;
				} 
				// If the node to be removed doesn't exist, do nothing
				break;
			}
			node = node->next;
		}
	}
}

void removeBefore(doubly_linked_list_t* list, int search /* Value to be searched for */){
	if (list->count != 0){
		dl_node_t *node = list->first;
		dl_node_t *tempNode;

		if (node->value == search){ // quick way to check the first value
			// There is no value to be removed before the first one
			return;
		}
		node = node->next; // since we checked the first one, let's move to the next one
	
		while(node != NULL){
			if (node->value == search){
				tempNode = node->prev;
				tempNode->prev->next = node; // said the node before the 'to be removed' node to point to the current node
				node->prev = tempNode->prev;
				free(tempNode);
				list->count--;
				break;
			}
			node = node->next;
		}
	}
}
void removeNode(doubly_linked_list_t* list, int search /* Value to be searched for */){
	if (list->count != 0){
		dl_node_t *node = list->first;
		if (node->value == search){ // checking the first value
			// All we have to do is just remove the top value
			removeTop(list);
			return;
		}
		node = node->next; // not the first one
		
		while(node != NULL){
			if (node->value == search){
				node->prev->next = node->next; // reset prev node pointer to point to next node
				if (node->next != NULL) node->next->prev = node->prev; // if node->next is null it will not have a prev pointer
				free(node);
				list->count--;
				break;
			}
			node = node->next;
		}
	}
}
void printList(doubly_linked_list_t* list){
	dl_node_t *node = list->first;
	int val;
	while(node != NULL){
		val = node->value;
		printf("%d \n", val);
		node = node->next;
	}
}

static void addFirst(doubly_linked_list_t* list, dl_node_t* node){
	// This is called on the occasion that the list is empty
	list->first = node;
	list->last = node;
}

int contains(doubly_linked_list_t* list, int item){
	dl_node_t *node = list->first;
	while(node != NULL){
		if (node->value == item) return 1;
		node = node->next;
	}
	return 0;
}

void copy(doubly_linked_list_t* list, doubly_linked_list_t* target){
	if( list->count !=0){
		// First let's copy the first item
		dl_node_t *newNode = malloc(sizeof (dl_node_t)); // this will hold temporary nodes
		dl_node_t *node;				   // this will hold nodes to the new linked list
		dl_node_t *oldNode = list->first;		   // this will hold nodes from the old linked list
		int i;					   // counter for loop
		target->first = newNode;
		node = target->first;
		node->value = oldNode->value;
		node->prev = NULL;
		while(oldNode->next != NULL){
			oldNode = oldNode->next;	// advance the node pointer
			newNode = malloc(sizeof (dl_node_t));	// allocate space for the new node
			node->next = newNode;
			newNode->prev = node;
			
			node = node->next;
			node->value = oldNode->value;
		}
		
		target->last = node;
		target->last->next = NULL; // make sure that last doesn't point anywhere
		
		// copy the count, of course
		target->count = list->count;
	}
}

void emptyDLL(doubly_linked_list_t* list){
	dl_node_t *node = list->first;
	while(node != NULL){
		free(node->prev);
		node = node->next;
	}
	free(node); // free the last node
	list->count = 0;
	list->first = NULL;
	list->last = NULL;
}
