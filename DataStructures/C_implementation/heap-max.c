#include "heap.h"

// Let's make the use of the preprocessor, shall we?
#define NODE_VAL node->value
#define RIGHT_CHILD node->right
#define LEFT_CHILD node->left
#define ROOT heap->root

static tree_node_t **add2Heap(tree_node_t **, int, heap_t *, int);
static tree_node_t **removeNode(heap_t *, tree_node_t *, int, tree_node_t **, int, int);
static tree_node_t *getRightMost(tree_node_t *, tree_node_t *, int, heap_t *, int);
static tree_node_t **upheap(tree_node_t *, tree_node_t *, int, heap_t *);
static void downheap(tree_node_t *, tree_node_t *, heap_t *, int);

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

	add2Heap(&ROOT, value, heap, 1);
	heap->size++;
}
void heap_remove(heap_t *heap, int value){
	/**
	 * A method to delete an item with @param value from the
	 * heap that can be called externally
	 */
	removeNode(heap, ROOT, value, NULL, 1, 0);
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
	heap->depth = 0; // needed because binary tree doesn't have depth variable
}
void copy_heap(heap_t *heap, heap_t *target){
	/**
	 * Calls generic method for binary trees
	 * to copy the heap
	 */
	copy_tree(heap, target);
	target->depth = heap->depth; // needed because binary tree doesn't have depth variable
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

static tree_node_t **removeNode(heap_t *heap, tree_node_t *node, int value, tree_node_t **parent, int depth, int position /* 1 - left, 0 - right */){
	/*
	 * A recursive method to remove the node from the tree
	 */
	if (node == NULL) {
		return;
	} else if (NODE_VAL == value){
		if (LEFT_CHILD == NULL && RIGHT_CHILD == NULL) { //removing a leaf
                if (parent == NULL) // root node to be remove
                    ROOT = NULL; //empty tree
                else if (position) // this node is parent's left child
                    (*parent)->left = NULL;
                else // this node is parent's right child
                    (*parent)->right = NULL;
		} else { // it's not a leaf
		    tree_node_t *new_node;
		    if (node == ROOT){ // NULL cannot be called with pointer to pointer
                new_node = getRightMost(node, NULL, depth, heap, 0);
            } else{
                new_node = getRightMost(node, *parent, depth, heap, 0);

                if (position) // this is parent's left child
                    (*parent)->left = new_node;
                else // this node is parent's right child
                    (*parent)->right = new_node;
            }
            // update the children
            new_node->left = LEFT_CHILD;
            new_node->right = RIGHT_CHILD;

            if (ROOT == node){ //root node is being deleted
                ROOT = new_node;
                downheap(new_node, NULL, heap, position);
            } else {
                downheap(new_node, *parent, heap, position);
            }
		}
		free(node);
	} // recursive calls
	 else if (NODE_VAL > value){
            tree_node_t **temp_node;

            // perform calls
            if (temp_node = removeNode(heap, RIGHT_CHILD, value, &node, depth + 1, 0))
                 return temp_node;
            else if(temp_node = removeNode(heap, LEFT_CHILD, value, &node, depth + 1, 1))
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
static void downheap(tree_node_t *node, tree_node_t *parent, heap_t *heap, int position /* 1 - left, 0 - right */){
    tree_node_t *temp_right, *temp_left; // temporary variables for the swap

    if (LEFT_CHILD != NULL && RIGHT_CHILD != NULL && NODE_VAL < LEFT_CHILD->value && NODE_VAL < RIGHT_CHILD->value){ // both of the children are larger than the parent
        // declare the pointer that will hold the maximum of the two parent
        tree_node_t *max = LEFT_CHILD->value > RIGHT_CHILD->value ? LEFT_CHILD : RIGHT_CHILD;
        int temp_pos; // for the recursive call

        if (ROOT == node){ // handling root
            ROOT = max;
        } else{
            // update parent pointer
            if (position)
                parent->left = max;
            else
                parent->right = max;
        }
        // typical swap operation
        temp_right = max->right;
        temp_left = max->left;

        if (max == LEFT_CHILD){
            max->right = node->right;
            max->left= node;
            temp_pos = 1; // temporary position update for the downheap recursive call
        } else{
            max->left = node->left;
            max->right = node;
            temp_pos = 0; // temporary position update for the downheap recursive call
        }

        LEFT_CHILD = temp_left;
        RIGHT_CHILD = temp_right;
        // swap done

        // call downheap again, to ensure the flow down the tree
        downheap(node, max, heap, temp_pos);


    } else if(LEFT_CHILD != NULL && NODE_VAL < LEFT_CHILD->value){
        if (ROOT == node){ // handling root
            ROOT = LEFT_CHILD;
        } else{
            // update parent pointer
            if (position)
                parent->left = LEFT_CHILD;
            else
                parent->right = LEFT_CHILD;
        }

        //swap
        temp_right = LEFT_CHILD->left;
        temp_left = LEFT_CHILD->right;

        LEFT_CHILD->left = node;
        LEFT_CHILD->right = node->right;

        LEFT_CHILD = temp_left;
        RIGHT_CHILD = temp_right;

        // swap done

        // call downheap again, to ensure the flow down the tree
        downheap(node, LEFT_CHILD, heap, 1);

    } else if(RIGHT_CHILD != NULL && NODE_VAL < RIGHT_CHILD->value){
        if (ROOT == node){ // handling root
            ROOT = RIGHT_CHILD;
        } else{
            // update parent pointer
            if (position)
                parent->left = RIGHT_CHILD;
            else
                parent->right = RIGHT_CHILD;
        }
        //swap
        temp_right = RIGHT_CHILD->left;
        temp_left = RIGHT_CHILD->right;

        RIGHT_CHILD->right = node;
        RIGHT_CHILD->left = node->left;

        LEFT_CHILD = temp_left;
        RIGHT_CHILD = temp_right;

        // swap done

        // call downheap again, to ensure the flow down the tree
        downheap(node, RIGHT_CHILD, heap, 0);
    }
    // If none of these happens, that means the node is in place
}
static tree_node_t **upheap(tree_node_t *node, tree_node_t *parent, int position /* 1 - left, 0 - right */, heap_t *heap){
	if (NODE_VAL > parent->value){
		// The nodes need to be exchanged

		// Temporary variables
        tree_node_t *temp_right = RIGHT_CHILD;
        tree_node_t *temp_left = LEFT_CHILD;

		if (position){
			// the node is the left child of the parent
			LEFT_CHILD = parent;
			RIGHT_CHILD = parent->right;
		} else{
			// the node is the right child of the parent
			RIGHT_CHILD = parent;
			LEFT_CHILD = parent->left;
		}

        if (ROOT == parent) // parent node is the root node => the root node pointer needs to be updated
			ROOT = node;
		parent->right = temp_right;
		parent->left = temp_left;

	} else if (parent->left != NULL && position && NODE_VAL > parent->left->value){ // need to make sure parent has a child
	    // This means that the parent's left child
	    // has already been exchanged with the
	    // current node
	    parent->left = node;

	} else if (parent->right != NULL && !position && NODE_VAL > parent->right->value){
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
        /**
                This cannot happen the first time around,
                because the leaves are checked off before
                there would be a chance for this method to
                be called
        */

        // we are at the leaves' level
        if (position){
            parent->left = NULL;	// resets the parent so that it wouldn't have left child
        } else{
            parent->right = NULL;	// -""- right child
        }
        return node;
    } else{
        if(found_node = getRightMost(RIGHT_CHILD, node, depth + 1, heap, 0)){
            return found_node;
        } else if(found_node = getRightMost(LEFT_CHILD, node, depth + 1, heap, 1)){
            return found_node;
        } else {
            return NULL;
        }
    }
}
