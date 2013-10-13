#include "../headers/LinkedQueue.h"
#include <cstdio>

int main(int argc, char* argv[])
{
    int a = 4;
    LinkedQueue<int> myQueue(4);

    printf("Queue current size: %d\n", myQueue.getCurrentSize());
    printf("Queue current element: %d\n", myQueue.getCurrentElement());

	return 0;
}
