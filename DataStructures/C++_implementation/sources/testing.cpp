#include "../headers/BTreeNode.h"
#include <cstdio>

int main(int argc, char* argv[])
{
    BTreeNode<int> myNode(5);
    BTreeNode<int> child(4, &myNode, NULL);

	return 0;
}
