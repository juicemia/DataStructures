#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

/*
 * For reasons presented in the book, current is always the node before
 * the actual "indexed" node (linked lists don't have indexes).
 * To make the code easier to read, I'm creating the following macro.
 *
 * DO NOT FORGET: current->next is itself a pointer! (double pointers... ew).
 *      It only points to a SingleNode. The element itself is inside the
 *      SingleNode, along with a pointer to the next SingleNode. Since it's a
 *      pointer you have to access it by using '->'
 */
#define TGT_NODE current->next

#include "SingleNode.h"

template <typename T>
class LinkedList
{
    private:
        SingleNode<T>* head;
        SingleNode<T>* tail;
        SingleNode<T>* current;
        int currentSize;

    public:
        LinkedList();
        ~LinkedList();

        //returns null if we're already at the tail
        T getCurrentElement();

        //insertion happens after current for reasons mentioned in the book
        int insert(T elem);
        int append(T elem);
        int remove();

        void jumpToHead();
        void jumpToTail();
        void nextNode();
        void prevNode();
        void jumpNode(int pos);

        int getCurrentPosition();
};

template <typename T>
LinkedList<T>::LinkedList()
{
    current = tail = head = new SingleNode<T>;
    currentSize = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    while(head != NULL)
    {
        current = head;
        head = head->next;
        delete current;
    }
}

template <typename T>
int LinkedList<T>::insert(T elem)
{
    TGT_NODE = new SingleNode<T>(elem, TGT_NODE);
    if(tail == current)
        tail = TGT_NODE;
    currentSize++;

    return currentSize;
}

template <typename T>
int LinkedList<T>::append(T elem)
{
    tail = tail->next = new SingleNode<T>(elem, NULL);
    currentSize++;

    return currentSize;
}

template <typename T>
int LinkedList<T>::remove()
{
    if(TGT_NODE == NULL)
        return currentSize;

    SingleNode<T>* tmp = TGT_NODE;

    if(TGT_NODE == tail){
        tail = current;
        tail->next = 0;

        currentSize--;
        jumpToTail();
        delete tmp;
        return currentSize;
    }

    TGT_NODE = TGT_NODE->next;

    currentSize--;
    delete tmp;

    return currentSize;
}

template <typename T>
T LinkedList<T>::getCurrentElement()
{
    return TGT_NODE->element;
}

template <typename T>
void LinkedList<T>::jumpToHead()
{
    current = head;
}

template <typename T>
void LinkedList<T>::jumpToTail()
{
    int i = 1;

    current = head;
    while(i < currentSize){
        current = TGT_NODE;
        i++;
    }
}

template <typename T>
void LinkedList<T>::nextNode()
{
    if(current != tail)
        current = TGT_NODE;
}

template <typename T>
void LinkedList<T>::prevNode()
{
    if(current != head){
        SingleNode<T>* tmp = current;
        current = head;
        while(TGT_NODE != tmp)
            current = TGT_NODE;
    }
}

template <typename T>
void LinkedList<T>::jumpNode(int pos)
{
    if(pos < currentSize && pos > 0){
        current = head;
        for(int i = 0; i < pos; i++){
            current = TGT_NODE;
        }
    }
}

template <typename T>
int LinkedList<T>::getCurrentPosition()
{
    SingleNode<T>* tmp = head;
    int i = 0;

    while(tmp != current){
        tmp = tmp->next;
        i++;
    }
    return i;
}

#endif //_LINKED_LIST_H_
