#include "SingleNode.h"

template <typename T>
class LinkedQueue
{
    private:
        SingleNode<T>* head;
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
    head = tail = NULL;
    currentSize = 0;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(T elem_init)
{
    head = tail = new SingleNode<T>(elem_init, NULL);
    currentSize = 1;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
    if(currentSize > 1)
        delete [] head;
    else if(currentSize == 1)
        delete head;
}

template <typename T>
int LinkedQueue<T>::getCurrentSize()
{
    return currentSize;
}

template <typename T>
T LinkedQueue<T>::getCurrentElement()
{
    return head->element;
}
