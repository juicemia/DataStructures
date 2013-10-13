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
        LinkedQueue(T* elem_init, int size);
        ~LinkedQueue();

        int getCurrentSize();
        T getCurrentElement();

        int enqueue(T elem);
        T dequeue();
};
