#include "../headers/BinarySearchTree.h"
#include <cstdio>

void print_int_node(BTreeNode<int>* tgt)
{
    printf("%d, ", tgt->getElement());
}

int main(int argc, char* argv[])
{
    BinarySearchTree<int>* myTree = new BinarySearchTree<int>(7);

    printf("Pre-order: \n");
    myTree->preorder(myTree->root, print_int_node);
	printf("\n");

	myTree->root->setLeftChild(new BTreeNode<int>(4));
	printf("Pre-order: \n");
	myTree->preorder(myTree->root, print_int_node);
	printf("\n");

	delete myTree;

	return 0;
}
