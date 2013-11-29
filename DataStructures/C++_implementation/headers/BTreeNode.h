#ifndef _B_TREE_NODE_H_
#define _B_TREE_NODE_H_

#define NULL 0

template <typename T>
class BTreeNode {
    T element;
    BTreeNode<T>* parent;
    BTreeNode<T>* left;
    BTreeNode<T>* right;

    public:
        BTreeNode(T);
        BTreeNode(T, BTreeNode<T>*, BTreeNode<T>*);
        BTreeNode(T, BTreeNode<T>*, BTreeNode<T>*, BTreeNode<T>*);
        ~BTreeNode();

        T getElement();
        BTreeNode<T>* getParent();
        BTreeNode<T>* getLeftChild();
        BTreeNode<T>* getRightChild();

        void setElement(T elem);
        BTreeNode<T>* setParent(BTreeNode<T>*);
        BTreeNode<T>* setLeftChild(BTreeNode<T>*);
        BTreeNode<T>* setRightChild(BTreeNode<T>*);
};

template <typename T>
BTreeNode<T>::BTreeNode(T elem)
{
    element = elem;
    parent = NULL;
    left = NULL;
    right = NULL;
}

template <typename T>
BTreeNode<T>::BTreeNode(T elem, BTreeNode<T>* l, BTreeNode<T>* r)
{
    element = elem;
    left = l;
    right = r;
}

template <typename T>
BTreeNode<T>::BTreeNode(T elem, BTreeNode<T>* p, BTreeNode<T>* l, BTreeNode<T>* r)
{
    element = elem;
    parent = p;
    left = l;
    right = r;
}

template <typename T>
BTreeNode<T>::~BTreeNode<T>()
{
    parent = NULL;
    left = NULL;
    right = NULL;
}

template <typename T>
T BTreeNode<T>::getElement()
{
    return element;
}

template <typename T>
BTreeNode<T>* BTreeNode<T>::getParent()
{
    return parent;
}

template <typename T>
BTreeNode<T>* BTreeNode<T>::getLeftChild()
{
    return left;
}

template <typename T>
BTreeNode<T>* BTreeNode<T>::getRightChild()
{
    return right;
}

template <typename T>
void BTreeNode<T>::setElement(T elem)
{
    element = elem;
}

template <typename T>
BTreeNode<T>* BTreeNode<T>::setParent(BTreeNode<T>* p)
{
    parent = p;
    return parent;
}

template <typename T>
BTreeNode<T>* BTreeNode<T>::setLeftChild(BTreeNode<T>* l)
{
    left = l;
    return left;
}

template <typename T>
BTreeNode<T>* BTreeNode<T>::setRightChild(BTreeNode<T>* r)
{
    right = r;
    return right;
}
#endif //_B_TREE_NODE_H_
