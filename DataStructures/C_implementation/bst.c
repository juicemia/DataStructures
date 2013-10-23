#include "bst.h"

#define NODE_VAL node->value
#define RIGHT_CHILD node->right
#define LEFT_CHILD node->left
#define ROOT tree->root

static void add2Tree(tree_node_t**, int);
static void removeTreeValue(tree_node_t **);
static void copyNode(tree_node_t *, tree_node_t **);
static void printNode(tree_node_t *);
static void removeNode(bst_t *, tree_node_t *, int, tree_node_t **);
static tree_node_t *getLeftMost(tree_node_t *, tree_node_t *);
static int findNode(tree_node_t *, int);


void tree_add(bst_t *tree, int value){
	/*
	 * A method to add to a tree that can be called externally
	 */
	add2Tree(&ROOT, value);
	tree->size++;
}
void tree_remove(bst_t *tree, int value){
	/**
	 * A method to delete an item with @param value from the
	 * tree that can be called externally
	 */
	removeNode(tree, ROOT, value, NULL);
	tree->size--;
}
int tree_peek_root(bst_t *bst){
	/*
	 * Displays the root of the tree
	 */
	if (bst->root != NULL){
		return bst->root->value;
	}
}
void empty_tree(bst_t *tree){
	/**
	 * Makes the tree empty
	 */
	removeTreeValue(&ROOT);
	tree->size = 0;
	ROOT = NULL;
}
void copy_tree(bst_t *tree, bst_t *target){
	/**
	 * Copies the tree from @param tree to @param target
	 */
	copyNode(ROOT, &target->root);
}
int tree_isEmpty(bst_t *tree){
	/*
	 * Simple check to check whether the tree is empty
	 */
	return tree->size == 0 ? 1 : 0;
}
int tree_size(bst_t *tree){
	/*
	 * Retrieves the tree size
	 */
	return tree->size;
}
void print_tree(bst_t *tree, int traversal){
	/**
	 * Prints the tree via inorder traversal
	 * @param traversal can hold three values: 0, 1, 2.
	 * 0 - preorder traversal printing
	 * 1 - inorder traversal printing
	 * 2 - postorder traversal printing
	 */
	switch(traversal){
        case 0:
            preorder(ROOT, printNode);
            break;
        case 1:
            inorder(ROOT, printNode);
            break;
        case 2:
            postorder(ROOT, printNode);
            break;
	}
}
int contains(bst_t *tree, int value){
	/**
	 * Checks whether the tree contains @param value
	 */
	return findNode(ROOT, value);
}
static int findNode(tree_node_t *node, int value){
	/*
	 * Local method to find a node with value @param value.
	 * If the node is not found, 0 is returned
	 */
	if (node == NULL) return 0;
	else if (NODE_VAL == value)	return 1;
	else if (NODE_VAL < value) return findNode(RIGHT_CHILD, value);
	else return findNode(LEFT_CHILD, value);
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
				ROOT = NULL; //empty tree
			} else	if((*parent)->value > (node)->value){ //this node is parent's left child
				(*parent)->left = NULL;
			} else { //this node is parent's right child
				(*parent)->right = NULL;
			}
			free(node);
			return;
		} else if((node)->right == NULL){ // it doesn't have right child; this means the left child will replace the node
			if (parent == NULL) { // root node to be remove
				ROOT = LEFT_CHILD; //empty tree
			} else if((*parent)->value > (node)->value){ //this node is parent's left child
				(*parent)->left = (node)->left;
			} else { //this node is parent's right child
				(*parent)->right = (node)->left;
			}
			free(node);
			return;
		} else if((node)->right->left == NULL){ // it has a right child that doesn't have a left child
			if (parent == NULL) { // root node to be remove
				ROOT = RIGHT_CHILD; //empty tree
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
				ROOT = left_most; //empty tree
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
		removeNode(tree, RIGHT_CHILD, value, &node);
	} else {
		removeNode(tree, LEFT_CHILD, value, &node);
	}

}

static void printNode(tree_node_t *node){
	printf("%d \n", NODE_VAL);
}
static void copyNode(tree_node_t *node, tree_node_t **target){
	/*
	 * The method copies the node from the @param node to the
	 * @param *target
	 */
	if (node == NULL){
		*target = NULL;
		return;
	}
	//pre-order traversal
	*target = malloc(sizeof(tree_node_t));
	(*target)->value = NODE_VAL;

	copyNode(LEFT_CHILD, &(*target)->left);
	copyNode(RIGHT_CHILD, &(*target)->right);
	free(node);
}
static void removeTreeValue(tree_node_t **node){
	/*
	 * Recursive method to remove each tree node one
	 * by one
	 */
	if (*node == NULL) return;
	//post-order traversal
	removeTreeValue(&(*node)->left);
	removeTreeValue(&(*node)->right);
	free(*node);
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
	if(LEFT_CHILD != NULL){
		getLeftMost(LEFT_CHILD, node);
	} else { // `node` is the leftmost child
		parent->left = NULL;	// resets the parent so that it wouldn't have left child
		return node;
	}
}
void inorder(tree_node_t *node, void (*callback)(tree_node_t *)){
    if (node == NULL) return;

    //in order traversal
    inorder(LEFT_CHILD, callback);
    callback(node);
    inorder(RIGHT_CHILD, callback);
}
void preorder(tree_node_t *node, void (*callback)(tree_node_t *)){
    if (node == NULL) return;

    //preorder traversal
    callback(node);
    inorder(LEFT_CHILD, callback);
    inorder(RIGHT_CHILD, callback);
}
void postorder(tree_node_t *node, void (*callback)(tree_node_t *)){
    if (node == NULL) return;

    //postorder traversal
    inorder(LEFT_CHILD, callback);
    inorder(RIGHT_CHILD, callback);
    callback(node);
}
