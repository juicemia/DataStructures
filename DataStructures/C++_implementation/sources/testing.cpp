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
    myTree.add(6);
    myTree.add(4);

    printf("Pre-order: \n");
    myTree.inOrder(print_int_node);

	return 0;
}
