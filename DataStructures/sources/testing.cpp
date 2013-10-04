#include "../headers/LinkedList.h"
#include <cstdio>

int main(int argc, char* argv[])
{
    LinkedList<int> myList;

    myList.insert(4);
    myList.append(5);
    myList.append(6);
    myList.append(7);

    printf("Current element: %d\n", myList.getCurrentElement());
    printf("Current position: %d\n", myList.getCurrentPosition());

    myList.jumpNode(3);
    printf("Current element: %d\n", myList.getCurrentElement());
    printf("Current position: %d\n", myList.getCurrentPosition());

	return 0;
}
