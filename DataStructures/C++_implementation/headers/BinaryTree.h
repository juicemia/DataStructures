/*
 * The Binary Tree class only covers methods that apply to a whole tree.
 *
 * Handling insertion/deletion of individual nodes is infeasible in this
 * structure because there's no sure way of knowing where the node needs to
 * be inserted/deleted. Where as in a Binary Search Tree, for example, there's a
 * sure way of knowing where the node goes by it's value in relation to other
 * nodes, in this tree there's no way of knowing.
 *
 * I admit this probably isn't a very useful data structure because there's no
 * built-in rule for organizing the data. But it's designed to give the user
 * maximum control over where they want their nodes to go.
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

        //traversals
        void preorder(BTreeNode<T>*, void (*func)(BTreeNode<T>*));
        void inorder(BTreeNode<T>*, void (*func)(BTreeNode<T>*));
        void postorder(BTreeNode<T>*, void (*func)(BTreeNode<T>*));
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
void BinaryTree<T>::preorder(BTreeNode<T>* node, void (*func)(BTreeNode<T>*))
{
    if(node == NULL)
        return;

    func(node);
    preorder(node->getLeftChild(), func);
    preorder(node->getRightChild(), func);
}

template <typename T>
void BinaryTree<T>::inorder(BTreeNode<T>* node, void (*func)(BTreeNode<T>*))
{
    if(node == NULL)
        return;

    inorder(node->getLeftChild(), func);
    func(node);
    inorder(node->getRightChild(), func);
}

template <typename T>
void BinaryTree<T>::postorder(BTreeNode<T>* node, void (*func)(BTreeNode<T>*))
{
    if(node == NULL)
        return;

    postorder(node->getLeftChild(), func);
    postorder(node->getRightChild(), func);
    func(node);
}
#endif //_BINARY_TREE_H_
