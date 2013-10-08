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
        SingleNode<T>* pop();
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

    if(currentSize == 0){
        top = new SingleNode<T>(elem, NULL);
    }

    top = top->next = new SingleNode<T>(elem, NULL);

    return currentSize;
}

#endif //_LINKED_STACK_H_
