#include "../headers/BinaryTree.h"
#include <cstdio>

int main(int argc, char* argv[])
{
    BinaryTree<int> myTree(3);
    //myTree.head = new BTreeNode<int>(4);

    printf("Tree head: %d\n", myTree.head->getElement());

    myTree.head->setLeftChild(new BTreeNode<int>(4));
    printf("Head->left: %d", myTree.head->getLeftChild()->getElement());

	return 0;
}
