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
        BTreeNode<T>* root;

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
    root = NULL;
}

template <typename T>
BinaryTree<T>::BinaryTree(T elem)
{
    root = new BTreeNode<T>(elem);
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
