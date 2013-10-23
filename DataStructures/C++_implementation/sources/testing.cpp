#include "../headers/BinaryTree.h"
#include <cstdio>

void print_int_node(BTreeNode<int>* node)
{
    printf("%d ", node->getElement());
}

int main(int argc, char* argv[])
{
    BinaryTree<int> myTree(3);
    printf("Tree head: %d\n", myTree.head->getElement());

    myTree.head->setLeftChild(new BTreeNode<int>(4));
    printf("Head->left: %d\n", myTree.head->getLeftChild()->getElement());

    myTree.head->setRightChild(new BTreeNode<int>(5));
    printf("Head->right: %d\n", myTree.head->getRightChild()->getElement());

    myTree.head->getLeftChild()->setRightChild(new BTreeNode<int>(6));

    myTree.postorder(myTree.head, print_int_node);

	return 0;
}
