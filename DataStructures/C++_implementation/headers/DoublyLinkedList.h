#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_

#include "DoubleNode.h"

template <typename T>
class DoublyLinkedList
{
    private:
        DoubleNode<T>* current;
        DoubleNode<T>* head;
        int currentSize;

    public:
        DoublyLinkedList();
        ~DoublyLinkedList();

        T getCurrentElement();
        int getCurrentSize();

        int insert(T elem);
        int append(T elem);
        int remove();

        void nextNode();
        void prevNode();
        void jumpNode(int pos);
        void jumpToHead(); //in this implementation the head is just the first element
        void jumpToTail(); //same as above except the tail is the last element
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    current = head = NULL;
    currentSize = 0;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    current = head;
    while(current != NULL){
        current = current->next;
        delete current;
    }
    delete head;
}

template <typename T>
T DoublyLinkedList<T>::getCurrentElement()
{
    return current->element;
}

template <typename T>
int DoublyLinkedList<T>::getCurrentSize()
{
    return currentSize;
}

template <typename T>
int DoublyLinkedList<T>::insert(T elem)
{
    currentSize++;

    if(current == NULL){
        current = head = new DoubleNode<T>(elem, NULL);

        return currentSize;
    }
    if(current->previous == NULL){
        current = new DoubleNode<T>(elem, current);
        head = current;
        current->next->previous = current;

        return currentSize;
    }

    current->previous = new DoubleNode<T>(elem, current, current->previous);

    return currentSize;
}

template <typename T>
int DoublyLinkedList<T>::append(T elem)
{
    currentSize++;
    if(current == NULL){
        current = head = new DoubleNode<T>(elem, NULL);

        return currentSize;
    }

    DoubleNode<T>* tmp = current;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = new DoubleNode<T>(elem, NULL, tmp);

    return currentSize;
}

template <typename T>
void DoublyLinkedList<T>::nextNode()
{
    if(current->next != NULL){
        current = current->next;
    }
}

template <typename T>
void DoublyLinkedList<T>::prevNode()
{
    if(current->previous != NULL){
        current = current->previous;
    }
}

template <typename T>
void DoublyLinkedList<T>::jumpNode(int pos)
{
    if(pos >= currentSize || pos < 0)
        return;

    current = head;
    for(int i = 0; i <= pos; i++)
        current = current->next;
}

template <typename T>
void DoublyLinkedList<T>::jumpToHead()
{
    current = head;
}

template <typename T>
void DoublyLinkedList<T>::jumpToTail()
{
    current = head;
    for(int i = 0; i < currentSize; i++)
        current = current->next;
}
#endif //_DOUBLY_LINKED_LIST_H_
