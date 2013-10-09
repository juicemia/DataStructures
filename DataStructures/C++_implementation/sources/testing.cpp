#include "../headers/LinkedStack.h"
#include <cstdio>

int main(int argc, char* argv[])
{
    LinkedStack<int> myStack;
    printf("Current size: %d\n", myStack.getCurrentSize());

    myStack.push(4);
    printf("Current size: %d\n", myStack.getCurrentSize());
    printf("Current element: %d\n", myStack.peek());

    myStack.push(5);
    printf("Current size: %d\n", myStack.getCurrentSize());
    printf("Current element: %d\n", myStack.peek());

    int popped = myStack.pop();
    printf("Current size: %d\n", myStack.getCurrentSize());
    printf("Current element: %d\n", myStack.peek());
    printf("Popped element: %d\n", popped);

    popped = myStack.pop();
    printf("Current size: %d\n", myStack.getCurrentSize());
    printf("Current element: %d\n", myStack.peek());
    printf("Popped element: %d\n", popped);

	return 0;
}
