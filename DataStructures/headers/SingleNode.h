/*
 * For use with anything that requires nodes (singly linked lists and etc.)
 */

#ifndef _SINGLE_NODE_H_
#define _SINGLE_NODE_H_

#define NULL 0

template <typename T>
class SingleNode
{
    public:
        T element;
        SingleNode* next;

        SingleNode();
        SingleNode(T elem, SingleNode* nxt);
};

template <typename T>
SingleNode<T>::SingleNode()
{
    next = NULL;
}

template <typename T>
SingleNode<T>::SingleNode(T elem, SingleNode* nxt)
{
    element = elem;
    next = nxt;
}

#endif //_SINGLE_NODE_H_
