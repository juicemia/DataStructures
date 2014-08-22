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
    currentSize = 0;
    currentIndex = 0;
    elements = NULL;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(T* elem_init, int size)
{
    currentIndex = 0;
    currentSize = size;
    elements = new T[size];
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

template <typename T>
int ArrayQueue<T>::enqueue(T elem)
{
    currentSize++;

    if(currentSize == 1){
        elements = new T;
        elements[0] = elem;

        return currentSize;
    }

    T* tmp = new T[currentSize];
    for(int i = 0; i < currentSize - 1; i++){
        tmp[i] = elements[i];
    }
    tmp[currentSize - 1] = elem;
    elements = tmp;

    return currentSize;
}

template <typename T>
T ArrayQueue<T>::dequeue()
{
    currentSize--;
    T ret = elements[0];

    if(currentSize == 0){
        delete elements;
        elements = NULL;

        return ret;
    }

    T* tmp = new T[currentSize];
    for(int i = 0; i < currentSize; i++){
        tmp[i] = elements[i + 1];
    }
    delete elements;
    elements = tmp;

    return ret;
}

#endif //_ARRAY_QUEUE_H_
