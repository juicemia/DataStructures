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

    printf("Searching for 3: \n");
    printf("%s", myTree.query(3) ? "PRESENT\n" : "MISSING\n");

    printf("Searching for 2: \n");
    printf("%s", myTree.query(2) ? "PRESENT\n" : "MISSING\n");

    printf("Searching for 7: \n");
    printf("%s", myTree.query(7) ? "PRESENT\n" : "MISSING\n");

	return 0;
}
