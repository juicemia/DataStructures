#include "../headers/LinkedQueue.h"
#include <cstdio>

int main(int argc, char* argv[])
{
    int a = 4;
    LinkedQueue<int> myQueue(4);

    printf("Queue current size: %d\n", myQueue.getCurrentSize());
    printf("Queue current element: %d\n", myQueue.getCurrentElement());

    myQueue.enqueue(5);

    printf("Queue current size: %d\n", myQueue.getCurrentSize());
    printf("Queue current element: %d\n", myQueue.getCurrentElement());

    a = myQueue.dequeue();
    printf("Queue current size: %d\n", myQueue.getCurrentSize());
    printf("Queue dequeued element: %d\n", a);
    printf("Queue current element: %d\n", myQueue.getCurrentElement());

	return 0;
}
