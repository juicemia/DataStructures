#include "SingleNode.h"

template <typename T>
class LinkedQueue
{
    private:
        SingleNode<T>* tail;
        int currentSize;

    public:
        LinkedQueue();
        LinkedQueue(T elem_init);
        ~LinkedQueue();

        int getCurrentSize();
        T getCurrentElement();

        int enqueue(T elem);
        T dequeue();
};

template <typename T>
LinkedQueue<T>::LinkedQueue()
{
    tail = NULL;
    currentSize = 0;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(T elem_init)
{
    tail = new SingleNode<T>(elem_init, NULL);
    currentSize = 1;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
    SingleNode<T>* tmp = tail;
    while(tmp->next != NULL){
        tmp = tmp->next;
        delete tmp;
    }
    delete tail;
    currentSize = 0;
}

template <typename T>
int LinkedQueue<T>::getCurrentSize()
{
    return currentSize;
}

template <typename T>
T LinkedQueue<T>::getCurrentElement()
{
    SingleNode<T>* tmp = tail;
    while(tmp->next != NULL)
        tmp = tmp->next;

    return tmp->element;
}

template <typename T>
int LinkedQueue<T>::enqueue(T elem)
{
    currentSize++;

    if(currentSize == 1){
        tail = new SingleNode<T>(elem, NULL);
        return currentSize;
    }

    tail = new SingleNode<T>(elem, tail);
    return currentSize;
}

template <typename T>
T LinkedQueue<T>::dequeue(){
    currentSize--;
    SingleNode<T>* tmp = tail;
    while(tmp->next->next != NULL)
        tmp = tmp->next;

    T ret = tmp->next->element;
    delete tmp->next;
    tmp->next = NULL;

    return ret;
}
