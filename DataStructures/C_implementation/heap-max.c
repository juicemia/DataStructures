#include "heap.h"

static tree_node_t **add2Heap(tree_node_t **, int, heap_t *, int);
static void removeNode(bst_t *, tree_node_t *, int, tree_node_t **);
static tree_node_t *getRightMost(tree_node_t *, tree_node_t *);
static tree_node_t **upheap(tree_node_t *, tree_node_t *, int, heap_t *);

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
	if (heap->size == (0x2 << (heap->depth - 1)))
        heap->depth--;
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

static void removeNode(heap_t *heap, tree_node_t *node, int value, tree_node_t **parent){
	/*
	 * A recursive method to remove the node from the tree
	 */
	if (node == NULL) {
		return;
	} else if (node->value == value){
		if (parent == NULL) { // root node to be remove
				heap->root = NULL; //empty tree
		} else {

		}
	} // recursive calls
	 else if (node->value > value){
            tree_node_t *temp_node;

            // perform calls
            if (temp_node = removeNode(heap, node->right, value, &node) || temp_node = removeNode(heap, node->left, value, &node))
                return temp_node;
	} else {
	    // it cannot be here since it's larger than the node's value
	    return NULL;
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
			child_node = upheap(*child_node, *node, 1, heap);
			return child_node; // successful call
		} else if (child_node = add2Heap(&(*node)->right, value, heap, depth + 1)){
			child_node = upheap(*child_node, *node, 0, heap);
			return child_node; // successful call
		} else {
			// OOPS, no space here, have to climb back a tree up one level
			return NULL;
		}
	}
}
static tree_node_t **upheap(tree_node_t *node, tree_node_t *parent, int position /* 1 - left, 0 - right */, heap_t *heap){
	if (node->value > parent->value){
		// The nodes need to be exchanged

		// Temporary variables
        tree_node_t *temp_right = node->right;
        tree_node_t *temp_left = node->left;

		if (position){
			// the node is the left child of the parent
			node->left = parent;
			node->right = parent->right;
		} else{
			// the node is the right child of the parent
			node->right = parent;
			node->left = parent->left;
		}

        if (heap->root == parent) // parent node is the root node => the root node pointer needs to be updated
			heap->root = node;
		parent->right = temp_right;
		parent->left = temp_left;

	} else if (parent->left != NULL && position && node->value > parent->left->value){ // need to make sure parent has a child
	    // This means that the parent's left child
	    // has already been exchanged with the
	    // current node
	    parent->left = node;

	} else if (parent->right != NULL && !position && node->value > parent->right->value){
        // Same with the right side
        parent->right = node;
	}
	return &node;
}
static tree_node_t *getRightMost(tree_node_t *node, tree_node_t *parent, int depth, heap_t *heap, int position /* 1 - left, 0 - right */){
	/**
	 * Retrieves the rightmost node of the @param parent
	 */

	 tree_node_t *found_node; // temporary node

    if (heap->depth == depth){
        // we are at the leaves' level
        if (position){
            parent->left = NULL;	// resets the parent so that it wouldn't have left child
        } else{
            parent->right = NULL;	// -""- right child
        }
        return node;
    } else{
        if(found_node = getRightMost(node->right, node, depth + 1, heap, 0)){
            return found_node;
        } else if(found_node = getRightMost(node->left, node, depth + 1, heap, 1)){
            return found_node;
        } else {
            return NULL;
        }
    }
}
