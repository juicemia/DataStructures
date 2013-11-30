#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include "BTreeNode.h"

template <typename T>
class BinarySearchTree {
    BTreeNode<T>* root;

    void addCore(T elem, BTreeNode<T>*, BTreeNode<T>*);
    bool removeCore(T, BTreeNode<T>*);

    void preOrderCore(BTreeNode<T>*, void (*func)(BTreeNode<T>*));
    void inOrderCore(BTreeNode<T>*, void (*func)(BTreeNode<T>*));
    void postOrderCore(BTreeNode<T>*, void (*func)(BTreeNode<T>*));

    bool queryCore(T, BTreeNode<T>*);

    public:
        BinarySearchTree();
        BinarySearchTree(T);

        BTreeNode<T>* getRoot();
        void setRoot(T);

        void add(T);
        bool remove(T);

        void preOrder(void (*func)(BTreeNode<T>*));
        void inOrder(void (*func)(BTreeNode<T>*));
        void postOrder(void (*func)(BTreeNode<T>*));

        bool query(T);
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
    root = NULL;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(T elem)
{
    root = new BTreeNode<T>(elem);
}

template <typename T>
BTreeNode<T>* BinarySearchTree<T>::getRoot()
{
    return root;
}

template <typename T>
void BinarySearchTree<T>::setRoot(T elem)
{
    root = new BTreeNode<T>(elem);
}

template <typename T>
void BinarySearchTree<T>::add(T elem)
{
    addCore(elem, NULL, root);
}

template <typename T>
void BinarySearchTree<T>::preOrder(void (*func)(BTreeNode<T>*))
{
    preOrderCore(root, func);
}

template <typename T>
void BinarySearchTree<T>::inOrder(void (*func)(BTreeNode<T>*))
{
    inOrderCore(root, func);
}

template <typename T>
void BinarySearchTree<T>::postOrder(void (*func)(BTreeNode<T>*))
{
    postOrderCore(root, func);
}

template <typename T>
bool BinarySearchTree<T>::query(T val)
{
    return queryCore(val, root);
}

template <typename T>
bool BinarySearchTree<T>::remove(T val)
{
    removeCore(val, root);
}

/***PRIVATE HELPER FUNCTIONS***/
template <typename T>
void BinarySearchTree<T>::addCore(T elem, BTreeNode<T>* parent, BTreeNode<T>* tgt)
{
    if(tgt == NULL){
        tgt = new BTreeNode<T>(elem);
        if(parent != NULL){
            if(elem < parent->getElement()){
                parent->setLeftChild(tgt);
            }else{
                parent->setRightChild(tgt);
            }
        }
    }else{
        if(elem < tgt->getElement()){
            addCore(elem, tgt, tgt->getLeftChild());
        }else{
            addCore(elem, tgt, tgt->getRightChild());
        }
    }
}

template <typename T>
void BinarySearchTree<T>::preOrderCore(BTreeNode<T>* node, void (*func)(BTreeNode<T>*))
{
    if(node == NULL)
        return;

    func(node);
    preOrderCore(node->getLeftChild(), func);
    preOrderCore(node->getRightChild(), func);
}

template <typename T>
void BinarySearchTree<T>::inOrderCore(BTreeNode<T>* node, void (*func)(BTreeNode<T>*))
{
    if(node == NULL)
        return;

    inOrderCore(node->getLeftChild(), func);
    func(node);
    inOrderCore(node->getRightChild(), func);
}

template <typename T>
void BinarySearchTree<T>::postOrderCore(BTreeNode<T>* node, void (*func)(BTreeNode<T>*))
{
    if(node == NULL)
        return;

    postOrderCore(node->getLeftChild(), func);
    postOrderCore(node->getRightChild(), func);
    func(node);
}

template <typename T>
bool BinarySearchTree<T>::queryCore(T val, BTreeNode<T>* val_node)
{
    if(val == val_node->getElement()){
        return true;
    }else if(val < val_node->getElement()){
        if(val_node->getLeftChild() != NULL){
            queryCore(val, val_node->getLeftChild());
        }else{
            return false;
        }
    }else{
        if(val_node->getRightChild() != NULL){
            queryCore(val, val_node->getRightChild());
        }else{
            return false;
        }
    }
}

template <typename T>
bool BinarySearchTree<T>::removeCore(T val, BTreeNode<T>* val_node)
{
    if(val == val_node->getElement()){
        /*
         * Restructure the tree's pointers before deleting the node
         */
        if(val_node->getLeftChild() != NULL && val_node->getRightChild() != NULL){

        }else{
            if(val_node->getLeftChild() != NULL){
                val_node->getLeftChild()->setParent(val_node->getParent());
                val_node->getParent()->setLeftChild(val_node->getLeftChild());
            }else if(val_node->getRightChild() != NULL){
                val_node->getRightChild()->setParent(val_node->getParent());
                val_node->getParent()->setRightChild(val_node->getRightChild());
            }
        }
        delete val_node;
        return true;
    }else if(val < val_node->getElement()){
        if(val_node->getLeftChild() != NULL){
            removeCore(val, val_node->getLeftChild());
        }else{
            return false;
        }
    }else{
        if(val_node->getRightChild() != NULL){
            removeCore(val, val_node->getRightChild());
        }else{
            return false;
        }
    }
}
#endif //_BINARY_SEARCH_TREE_H_
