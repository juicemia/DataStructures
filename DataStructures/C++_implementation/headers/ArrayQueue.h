#ifndef _ARRAY_QUEUE_H_
#define _ARRAY_QUEUE_H_

#define NULL 0

template <typename T>
class ArrayQueue
{
    private:
        T* elements;
        int currentSize;
        int currentIndex;

    public:
        ArrayQueue();
        ArrayQueue(int size);
        ArrayQueue(T* elem_init, int size);
        ~ArrayQueue();

        int getCurrentSize();
        T getCurrentElement();

        int enqueue(T elem);
        T dequeue();
};

template <typename T>
ArrayQueue<T>::ArrayQueue()
{
    elements = NULL;
    currentSize = 0;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(int size)
{
    elements = new T[size];
    currentSize = size;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(T* elem_init, int size)
{
    elements = new T[size];
    currentSize = size;
    for(int i = 0; i < currentSize; i++){
        elements[i] = elem_init[i];
    }
}

template <typename T>
ArrayQueue<T>::~ArrayQueue()
{
    if(currentSize > 1)
        delete [] elements;
    else if(currentSize == 1)
        delete elements;
}

template <typename T>
int ArrayQueue<T>::getCurrentSize()
{
    return currentSize;
}

template <typename T>
T ArrayQueue<T>::getCurrentElement()
{
        return elements[0];
}

#endif //_ARRAY_QUEUE_H_
