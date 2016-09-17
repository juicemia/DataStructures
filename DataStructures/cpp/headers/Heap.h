#ifndef _HEAP_H_
#define _HEAP_H_

/** 
 * The Heap class implements a heap in a fashion similar to
 * that presented in the book. It uses a comparison class to
 * toggle between min-heap and max-heap.
 *
 * The Heap class uses an array representation for the binary
 * tree. This is more efficient than using pointers for the
 * nodes because the heap is a complete binary tree, which in
 * turn means that the array will be neatly packed at all times.
 * This allows several formulas to emerge for finding relatives
 * to a given node in the tree.
 */

 template<typename T, typename Comp>
 class Heap {
     T* array;
     int size;

     void swap(int, int);

     public:
        int maxsize;

        Heap(int maxsz) {
            maxsize = maxsz;
            T tmp[maxsz];
            array = tmp;
            size = 0;
        }

        bool isLeaf(int);
        int parent(int);
        int insert(T);
 };

template<typename T, typename Comp>
bool Heap<T, Comp>::isLeaf(int pos)
{
    return (pos >= size / 2) && (pos < size);
}

// Here we deviate from the book, so that the user of the
// heap can know where the inserted element ended up
// right away.
template<typename T, typename Comp>
int Heap<T, Comp>::insert(T elem)
{
    if (size >= maxsize) {
        return -1;
    }

    int current = size++;
    array[current] = elem;

    while(current != 0 &&
        Comp::compare(array[current], array[parent(current)]))
    {
        swap(current, parent(current));
        current = parent(current);
    }

    return current;
}

template<typename T, typename Comp>
int Heap<T, Comp>::parent(int pos)
{
    return (pos - 1) / 2;
}

template<typename T, typename Comp>
void Heap<T, Comp>::swap(int i, int j) {
    T tmp = array[j];
    array[j] = array[i];
    array[i] = tmp;
}

#endif // _HEAP_H_
