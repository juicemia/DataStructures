#include "../headers/BinarySearchTree.h"
#include <cstdio>

void print_int_node(BTreeNode<int>* tgt)
{
    printf("%d, ", tgt->getElement());
}

int main(int argc, char* argv[])
{
    BinarySearchTree<int> myTree(5);
    myTree.add(3);

    printf("Pre-order: \n");
    myTree.preOrder(print_int_node);

	return 0;
}
