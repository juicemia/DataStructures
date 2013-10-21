#include "heap.h"

static tree_node_t **add2Heap(tree_node_t **, int, heap_t *, int);
static void removeNode(bst_t *, tree_node_t *, int, tree_node_t **);
static tree_node_t *getLeftMost(tree_node_t *, tree_node_t *);
static void upheap(tree_node_t **, tree_node_t *, int, heap_t *);

void heap_add(heap_t *heap, int value){
	/*
	 * A method to add to a heap that can be called externally
	 */

	/*
	 * This means that the creation of new layer is needed, since
	 * heap is a complete tree
	 */
	if (heap->size == ((0x2 << (heap->depth - 1)) - 1)){
        /*
            2^(heap->depth) wouldn't work
            for an unknown reason, so I raise 2 to the heap->depth power
            by shifting the neccessary bits to the left.

            No idea why 2^x is inaccurate though
        */
		heap->depth++;
	} else if (!heap->size){
		// heap is empty
		heap->size = 0;
		heap->depth = 1;
	}

	add2Heap(&heap->root, value, heap, 1);
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
	copy_tree(heap, target);
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
static tree_node_t **add2Heap(tree_node_t** node, int value, heap_t *heap, int depth){
	/*
	 * A recursive method to add a @param value to
	 * the heap, in a location, where it belongs
	 *
	 * Asymptotic complexity of the addition to the heap is the same as
	 * of the binary tree - O(lg(n))
	 */

	tree_node_t **child_node; // temporary pointer to pointer to node for the upheap calls

	if(*node == NULL && heap->depth == depth){ // good place to insert the node
		*node = malloc(sizeof(tree_node_t));
		(*node)->value = value;
		return node;
	} else if (heap->depth == depth){
		//reached bottom depth but it's already occupied
		return NULL;
	}
	// if it comes here, then regular climbing down the tree
	else { // just insert anywhere possible
		// always start with the left child
		if (child_node = add2Heap(&(*node)->left, value, heap, depth + 1)){
			upheap(child_node, *node, 1, heap);
			return child_node; // successful call
		} else if (child_node = add2Heap(&(*node)->right, value, heap, depth + 1)){
			upheap(child_node, *node, 0, heap);
			return child_node; // successful call
		} else {
			// OOPS, no space here, have to climb back a tree up one level
			return NULL;
		}
	}
}
static void upheap(tree_node_t **node, tree_node_t *parent, int position /* 1 - left, 0 - right */, heap_t *heap){
	if ((*node)->value > (parent)->value){
		// The nodes need to be exchanged

		if (position){
			// the node is the left child of the parent
			(*node)->left = parent;
			(*node)->right = (parent)->right;
		} else{
			// the node is the right child of the parent
			(*node)->right = parent;
			(*node)->left = (parent)->left;
		}

        if (heap->root == parent) // parent node is the root node => the root node pointer needs to be updated
			heap->root = *node;
		(parent)->right = NULL;
		(parent)->left = NULL;

	}
}
static tree_node_t *getLeftMost(tree_node_t *node, tree_node_t *parent){
	/**
	 * Retrieves the leftmost node of the @param parent
	 */
	if(node->left != NULL){
		getLeftMost(node->left, node);
	} else { // `node` is the leftmost child
		parent->left = NULL;	// resets the parent so that it wouldn't have left child
		return node;
	}
}
