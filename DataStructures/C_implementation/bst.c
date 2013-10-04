#include "bst.h"

static void add2Tree(tree_node_t**, int);
static void removeTreeValue(tree_node_t **);
static void copyNode(tree_node_t *, tree_node_t **);
static void printNode(tree_node_t *);
static void removeNode(bst_t *, tree_node_t *, int, tree_node_t **);
static tree_node_t *getLeftMost(tree_node_t *, tree_node_t *);
static int findNode(tree_node_t *, int);


void tree_add(bst_t *tree, int value){
	add2Tree(&tree->root, value);
	tree->size++;	
}
void tree_remove(bst_t *tree, int value){
	removeNode(tree, tree->root, value, NULL);
	tree->size--;
}
int tree_peek_root(bst_t *bst){
	if (bst->root != NULL){
		return bst->root->value;
	}
}
void empty_tree(bst_t *tree){
	removeTreeValue(&tree->root);
	tree->size = 0;
	tree->root = NULL;
}
void copy_tree(bst_t *tree, bst_t *target){
	copyNode(tree->root, &target->root);
}
int tree_isEmpty(bst_t *tree){
	return tree->size == 0 ? 1 : 0;
}
int tree_size(bst_t *tree){
	return tree->size;
}
void print_tree(bst_t *tree){
	printNode(tree->root);
}
int contains(bst_t *tree, int value){
	return findNode(tree->root, value);
}
static int findNode(tree_node_t *node, int value){
	if (node == NULL) return 0;
	else if (node->value == value)	return 1;
	else if (node->value < value) return findNode(node->right, value);
	else return findNode(node->left, value);
}
static void removeNode(bst_t *tree, tree_node_t *node, int value, tree_node_t **parent){
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

static void printNode(tree_node_t *node){	
	if (node == NULL) return;
	//in order traversal
	printNode(node->left);
	printf("%d \n", node->value);
	printNode(node->right);
	
}
static void copyNode(tree_node_t *node, tree_node_t **target){
	if (node == NULL){
		*target = NULL;
		return;	
	}
	//pre-order traversal
	*target = malloc(sizeof(tree_node_t));
	(*target)->value = node->value;

	copyNode(node->left, &(*target)->left);
	copyNode(node->right, &(*target)->right);
	free(node);
}
static void removeTreeValue(tree_node_t **node){
	if (*node == NULL) return;
	//post-order traversal
	removeTreeValue(&(*node)->left);
	removeTreeValue(&(*node)->right);
	free(*node);
}
static void add2Tree(tree_node_t** node, int value){
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
	if(node->left != NULL){
		getLeftMost(node->left, node);
	} else { // `node` is the leftmost child
		parent->left = NULL;	// resets the parent so that it wouldn't have left child
		return node;
	}
}
