/*
 * The Binary Tree class only covers methods that apply to a whole tree.
 * Since a Node can also be considered a tree (it's a subtree of the whole tree)
 * inserting/appending/removing are handled by the user. This is to give
 * maximum control to users over where they put their nodes with minimum
 * overhead. I haven't been able to think up an efficient way to allow a user
 * to choose where exactly they want their nodes. It's much easier to have
 * the BTreeNode's own setter methods return the address of the node they
 * just created. Since there's no way of knowing exactly where the node is going
 * to be before runtime, it's much easier for the user to keep track of exactly
 * how their tree is looking. It also gives the user more control because
 * there's no deterministic method for placing new nodes and removing old ones.
 * The user gets to pick what side simply by manipulating the variables they
 * create, or by keeping track of where they are in relationship to the head.
 */

#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include "BTreeNode.h"

template <typename T>
class BinaryTree {
    public:
        BTreeNode<T>* head;

        BinaryTree();
        BinaryTree(T);
};

template <typename T>
BinaryTree<T>::BinaryTree()
{
    head = NULL;
}

template <typename T>
BinaryTree<T>::BinaryTree(T elem)
{
    head = new BTreeNode<T>(elem);
}

#endif //_BINARY_TREE_H_
