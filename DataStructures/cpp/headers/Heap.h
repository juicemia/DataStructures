/** 
 * The Heap class implements a heap in a fashion similar to
 * that presented in the book. It uses a comparison class to
 * toggle between min-heap and max-heap.
 *
 * The Heap class uses an array representation for the binary
 * tree. This is more efficient than using pointers for the
 * nodes because the heap is a complete binary tree, which in
 * turn means that the array will be neatly packed at all times.
 */

 template<typename T, typename Comp>
 class Heap {
     T* array;

     public:
        Heap(int size) {
            T tmp[size];

            array = tmp;
        }
 };
