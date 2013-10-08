#ifndef _DOUBLE_NODE_H_
#define _DOUBLE_NODE_H_

#define NULL 0

template <typename T>
class DoubleNode
{
    public:
        T element;
        DoubleNode* next;
        DoubleNode* previous;

        DoubleNode();
        DoubleNode(T elem, DoubleNode* nxt);
        DoubleNode(T elem, DoubleNode* nxt, DoubleNode* prev);
};

template <typename T>
DoubleNode<T>::DoubleNode()
{
    next = NULL;
    previous = NULL;
}

template <typename T>
DoubleNode<T>::DoubleNode(T elem, DoubleNode* nxt)
{
    element = elem;
    next = nxt;
}

template <typename T>
DoubleNode<T>::DoubleNode(T elem, DoubleNode* nxt, DoubleNode* prev)
{
    element = elem;
    next = nxt;
    previous = prev;
}

#endif //_DOUBLE_NODE_H_
