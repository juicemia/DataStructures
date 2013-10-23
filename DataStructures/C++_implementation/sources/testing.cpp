#include "../headers/BinaryTree.h"
#include <cstdio>

void print_int_node(BTreeNode<int>* node)
{
    printf("%d ", node->getElement());
}

int main(int argc, char* argv[])
{
    BinaryTree<int> myTree(3);
    printf("Tree root: %d\n", myTree.root->getElement());

    myTree.root->setLeftChild(new BTreeNode<int>(4));
    printf("Root->left: %d\n", myTree.root->getLeftChild()->getElement());

    myTree.root->setRightChild(new BTreeNode<int>(5));
    printf("Root->right: %d\n", myTree.root->getRightChild()->getElement());

    myTree.root->getLeftChild()->setRightChild(new BTreeNode<int>(6));

    myTree.postorder(myTree.root, print_int_node);
	printf("\n");

	return 0;
}
