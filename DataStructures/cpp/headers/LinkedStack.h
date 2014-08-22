#ifndef _LINKED_STACK_H_
#define _LINKED_STACK_H_

#include "SingleNode.h"

template <typename T>
class LinkedStack
{
    private:
        SingleNode<T>* top;
        int currentSize;

    public:
        LinkedStack();
        ~LinkedStack();

        int getCurrentSize();

        int push(T elem);
        T pop();
        T peek();
};

template <typename T>
LinkedStack<T>::LinkedStack()
{
    currentSize = 0;
}

template <typename T>
LinkedStack<T>::~LinkedStack()
{
    if(currentSize > 0){
        SingleNode<T>* tmp = top;
        while(tmp->next != NULL){
            tmp = tmp->next;
            delete tmp;
        }
        delete top;
    }
}

template <typename T>
int LinkedStack<T>::getCurrentSize()
{
    return currentSize;
}

template <typename T>
int LinkedStack<T>::push(T elem)
{
    currentSize++;

    if(currentSize == 1){
        top = new SingleNode<T>(elem, NULL);

        return currentSize;
    }

    top = new SingleNode<T>(elem, top);

    return currentSize;
}

template <typename T>
T LinkedStack<T>::pop()
{
    T ret = top->element;
    currentSize--;

    if(currentSize == 0){
        delete top;
        return ret;
    }

    SingleNode<T>* tmp = top;

    top = top->next;
    delete tmp;
    return ret;
}

template <typename T>
T LinkedStack<T>::peek()
{
    if(currentSize > 0)
        return top->element;
}

#endif //_LINKED_STACK_H_
