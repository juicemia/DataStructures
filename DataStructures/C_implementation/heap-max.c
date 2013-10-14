#include "heap.h"

static void heap2Tree(tree_node_t**, int);
static void copyNode(tree_node_t *, tree_node_t **);
static void printNode(tree_node_t *);
static void removeNode(bst_t *, tree_node_t *, int, tree_node_t **);
static tree_node_t *getLeftMost(tree_node_t *, tree_node_t *);


void heap_add(heap_t *heap, int value){
	/*
	 * A method to add to a heap that can be called externally
	 */
	add2Heap(&heap->root, value);
	heap->size++;	
}
void heap_remove(heap_t *heap, int value){
	/**
	 * A method to delete an item with @param value from the
	 * heap that can be called externally
	 */
	removeNode(heap, heap->root, value, NULL);
	heap->size--;
}
int heap_peek_top(heap_t *heap){
	/*
	 * Calls generic method for binary trees
	 * to get the top of the heap
	 */
	return tree_peek_root(heap);
}
void empty_heap(heap_t *heap){
	/**
	 * Calls generic method for binary trees
	 * to empty the heap
	 */
	empty_tree(heap);
}
void copy_heap(heap_t *heap, heap_t *target){
	/**
	 * Calls generic method for binary trees
	 * to copy the heap
	 */
	copyTree(heap, target);
}
int heap_isEmpty(heap_t *heap){
	/*
	 * Simple check to check whether the heap is empty
	 */
	return heap->size == 0 ? 1 : 0;
}
int heap_size(heap_t *heap){
	/*
	 * Retrieves the heap size
	 */
	return heap->size;
}
void print_heap(heap_t *heap){
	/*
	 * Calls generic method for binary trees
	 * to print the heap
	 */
	print_tree(heap);
}
int contains_heap(heap_t *heap, int value){
	/**
	 * Calls generic method for binary trees
	 * to check whether a heap contains 
	 * @param value
	 */
	return contains(heap, value);
}

static void removeNode(bst_t *tree, tree_node_t *node, int value, tree_node_t **parent){
	/*
	 * A recursive method to remove the node from the tree
	 */
	if (node == NULL) {
		return;
	} else if ((node)->value == value){
		if ((node)->left == NULL && (node)->right == NULL){ // a leaf
			if (parent == NULL) { // root node to be remove
				tree->root = NULL; //empty tree
			} else	if((*parent)->value > (node)->value){ //this node is parent's left child
				(*parent)->left = NULL;
			} else { //this node is parent's right child
				(*parent)->right = NULL;
			}
			free(node);
			return;	
		} else if((node)->right == NULL){ // it doesn't have right child; this means the left child will replace the node
			if (parent == NULL) { // root node to be remove
				tree->root = node->left; //empty tree
			} else if((*parent)->value > (node)->value){ //this node is parent's left child
				(*parent)->left = (node)->left;
			} else { //this node is parent's right child
				(*parent)->right = (node)->left;
			}
			free(node);
			return;	
		} else if((node)->right->left == NULL){ // it has a right child that doesn't have a left child
			if (parent == NULL) { // root node to be remove
				tree->root = node->right; //empty tree
			} else if((*parent)->value > (node)->value){ //this node is parent's left child
				(*parent)->left = (node)->right;
			} else { //this node is parent's right child
				(*parent)->right = (node)->right;
			}
			(node)->right->left = (node)->left;	//the new node repoints to the removed node's left child
			free(node);
			return;	
		} else { // it has a right child that has a left child

			// need to find left-most child
			tree_node_t* left_most = getLeftMost((node)->right->left, (node)->right);
	
			if (parent == NULL) { // root node to be remove
				tree->root = left_most; //empty tree
			} else if((*parent)->value > (node)->value){ //this node is parent's left child
				(*parent)->left = left_most;
			} else { //this node is parent's right child
				(*parent)->right = left_most;
			}
			left_most->left = (node)->left; //the new node repoints to the removed node's left child
			left_most->right = (node)->right; // the new node is the parent of its previous parent
			free(node);
			return;
		}
	} else if ((node)->value < value){
		removeNode(tree, node->right, value, &node);
	} else {
		removeNode(tree, node->left, value, &node);
	}
	
}
static void add2Tree(tree_node_t** node, int value){
	/*
	 * A recursive method to add a @param value to 
	 * the tree, in a location, where it belongs
	 */
	if(*node == NULL){// empty tree
		*node = malloc(sizeof(tree_node_t));
		(*node)->value = value;
		
		return;
	} else if((*node)->value < value) { // node value is smaller
		return add2Tree(&(*node)->right, value);
	} else { // node value is either larger or equal
		return add2Tree(&(*node)->left, value);
	}
}
static tree_node_t *getLeftMost(tree_node_t *node, tree_node_t *parent){
	/*
	 * Retrieves the leftmost node of the @param parent
	 */
	if(node->left != NULL){
		getLeftMost(node->left, node);
	} else { // `node` is the leftmost child
		parent->left = NULL;	// resets the parent so that it wouldn't have left child
		return node;
	}
}
