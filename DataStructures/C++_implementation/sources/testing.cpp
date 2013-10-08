#include "../headers/DoublyLinkedList.h"
#include <cstdio>

int main(int argc, char* argv[])
{
    DoublyLinkedList<int> myList;

    myList.insert(4);
    //printf("Current element: %d\n", myList.getCurrentElement());

    myList.insert(5);
    //printf("Current element: %d\n", myList.getCurrentElement());

    myList.append(6);
    //myList.jumpToTail();
    //printf("Current element: %d\n", myList.getCurrentElement());

    myList.jumpToHead();
    for(int i = 0; i < myList.getCurrentSize(); i++){
        printf("Current element: %d\n", myList.getCurrentElement());
        myList.nextNode();
    }

	return 0;
}
