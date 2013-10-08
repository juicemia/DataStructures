#include "../headers/LinkedStack.h"
#include <cstdio>

int main(int argc, char* argv[])
{
    LinkedStack<int> myStack;
    int size = myStack.getCurrentSize();
    printf("Current size: %d\n", size);

    myStack.push(4);
    size = myStack.getCurrentSize();
    printf("Current size:%d\n", size);

    myStack.push(5);
    size = myStack.getCurrentSize();
    printf("Current size:%d\n", size);

	return 0;
}
