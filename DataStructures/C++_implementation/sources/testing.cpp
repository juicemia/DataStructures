#include "../headers/BinaryTree.h"
#include <cstdio>

int main(int argc, char* argv[])
{
    BinaryTree<int> myTree(3);
    printf("Tree head: %d\n", myTree.head->getElement());

    myTree.head->setLeftChild(new BTreeNode<int>(4));
    printf("Head->left: %d\n", myTree.head->getLeftChild()->getElement());

    myTree.head->setRightChild(new BTreeNode<int>(5));
    printf("Head->right: %d", myTree.head->getRightChild()->getElement());

	return 0;
}
