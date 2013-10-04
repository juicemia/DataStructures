#include "linkedList.h"

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
		newNode->next = list->first;
		list->first = newNode;	
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
		list->last->next = newNode;
		list->last = newNode;	
	}
	list->count++;
}
void removeTop(linked_list_t* list){
	if (list->count != 0){
		list->count--;
		node_t *tempNode = list->first;
		list->first = list->first->next;
		free(tempNode); // free the removed memory
	}
}
void removeBottom(linked_list_t* list){
	if (list->count != 0){	
		list->count--;
		node_t *node = list->first;
		node_t *prevNode = node;
		node_t *tempNode;	
		
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
void insertAfter(linked_list_t* list, int search /* Value to be searched for */, int newVal){
	if (list->count != 0){
		node_t *node = list->first;
		node_t *newNode = malloc(sizeof (node_t));
		newNode->value = newVal;
		while(node != NULL){
			if (node->value == search){
				newNode->next = node->next;
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
void insertBefore(linked_list_t* list, int search /* Value to be searched for */, int newVal){
	if (list->count != 0){
		node_t *node = list->first;
		node_t *prevNode = node;
		node_t *newNode = malloc(sizeof (node_t));
		newNode->value = newVal;
		if (node->value == search){ // quick way to check the first value
			addTop(list, newVal);
			return;
		}
		node = node->next; // since we checked the first one, let's move to the next one

		while(node != NULL){
			if (node->value == search){
				newNode->next = node;
				prevNode->next = newNode;
				list->count++;
				break;
			}
			prevNode = node;
			node = node->next;
		}
	} else {
		addTop(list, newVal);
	}
}
void removeAfter(linked_list_t* list, int search /* Value to be searched for */){
	if (list->count != 0){
		node_t *node = list->first;
		node_t *tempNode;
		while(node != NULL){
			if (node->value == search){
				tempNode = node->next;
				if (tempNode != NULL) {
					// The node to be removed exists
					node->next = tempNode->next;
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

void removeBefore(linked_list_t* list, int search /* Value to be searched for */){
	if (list->count != 0){
		node_t *node = list->first;
		node_t *tempNode;
		node_t *prevNode = node;
		node_t *prevPrevNode = node; // the node before the previous node

		if (node->value == search){ // quick way to check the first value
			// There is no value to be removed before the first one
			return;
		}
		node = node->next; // since we checked the first one, let's move to the next one
		if (node->value == search){ // checking the second value
			// All we have to do is just remove the top value
			removeTop(list);
			return;
		}
		prevNode = node;
		node = node->next; // not first two; move on
		
		while(node != NULL){
			if (node->value == search){
				tempNode = prevNode;
				prevPrevNode->next = node; // said the node before the 'to be removed' node to point to the current node
				free(tempNode);
				list->count--;
				break;
			}
			
			prevPrevNode = prevNode;
			prevNode = node;
			node = node->next;
		}
	}
}
void removeNode(linked_list_t* list, int search /* Value to be searched for */){
	if (list->count != 0){
		node_t *node = list->first;
		node_t *prevNode = node;
		if (node->value == search){ // checking the first value
			// All we have to do is just remove the top value
			removeTop(list);
			return;
		}
		node = node->next; // not the first one
		
		while(node != NULL){
			if (node->value == search){
				prevNode->next = node->next; // reset prev node pointer to point to next node
				free(node);
				list->count--;
				break;
			}
			
			prevNode = node;
			node = node->next;
		}
	}
}
void printList(linked_list_t* list){
	node_t *node = list->first;
	int val;
	while(node != NULL){
		val = node->value;
		printf("%d \n", val);
		node = node->next;
	}
}

static void addFirst(linked_list_t* list, node_t* node){
	// This is called on the occasion that the list is empty
	list->first = node;
	list->last = node;
}

int contains(linked_list_t* list, int item){
	node_t *node = list->first;
	while(node != NULL){
		if (node->value == item) return 1;
		node = node->next;
	}
	return 0;
}

void copy(linked_list_t* list, linked_list_t* target){
	if( list->count !=0){
		// First let's copy the first item
		node_t *newNode = malloc(sizeof (node_t)); // this will hold temporary nodes
		node_t *node;				   // this will hold nodes to the new linked list
		node_t *oldNode = list->first;		   // this will hold nodes from the old linked list
		int i;					   // counter for loop
		target->first = newNode;
		node = target->first;
		node->value = oldNode->value;
		for(i = 1; i<list->count && oldNode->next != NULL; i++){
			oldNode = oldNode->next;
			newNode = malloc(sizeof (node_t));
			node->next = newNode;
			node = node->next;
			node->value = oldNode->value;
		}
		target->last = node;
		target->last->next = NULL; // make sure that last doesn't point anywhere
		
		// copy the count, of course
		target->count = list->count;
	}
}

void emptyLL(linked_list_t* list){
	node_t *node = list->first;
	node_t *prevNode = list->first;
	while(node != NULL){
		prevNode = node;
		node = node->next;
		free(prevNode);
	}
	free(node); // free the last node
	list->count = 0;
	list->first = NULL;
	list->last = NULL;
}
