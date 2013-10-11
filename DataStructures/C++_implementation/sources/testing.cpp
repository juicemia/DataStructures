#include "../headers/ArrayQueue.h"
#include <cstdio>

int main(int argc, char* argv[])
{
    ArrayQueue<int> myQueue;

    myQueue.enqueue(5);
    printf("myQueue.enqueue(5);\n");
    printf("Current size: %d\n", myQueue.getCurrentSize());
    printf("Current element: %d\n\n", myQueue.getCurrentElement());

    myQueue.enqueue(6);
    printf("myQueue.enqueue(6);\n");
    printf("Current size: %d\n", myQueue.getCurrentSize());
    printf("Current element: %d\n\n", myQueue.getCurrentElement());

    int dqed = myQueue.dequeue();
    printf("myQueue.dequeue();\n");
    printf("Current size: %d\n", myQueue.getCurrentSize());
    printf("Dequeued element: %d\n", dqed);
    printf("Current element: %d\n\n", myQueue.getCurrentElement());

    dqed = myQueue.dequeue();
    printf("myQueue.dequeue();\n");
    printf("Current size: %d\n", myQueue.getCurrentSize());
    printf("Dequeued element: %d\n", dqed);

	return 0;
}
