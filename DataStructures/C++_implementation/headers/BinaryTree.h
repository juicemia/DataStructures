#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include "BTreeNode.h"

template <typename T>
class BinaryTree {
    BTreeNode<T>* head;

    public:
        BinaryTree();
        BinaryTree(T);

        void insert(T, BTreeNode<T>*);
        void append(T, BTreeNode<T>*);
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

template <typename T>
void BinaryTree<T>::insert(T elem, BTreeNode<T>* c)
{

}

#endif //_BINARY_TREE_H_
