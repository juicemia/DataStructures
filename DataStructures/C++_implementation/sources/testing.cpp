#include "../headers/DoublyLinkedList.h"
#include <cstdio>

int main(int argc, char* argv[])
{
    DoublyLinkedList<int> myList;

    myList.insert(4);
    //printf("Current element: %d\n", myList.getCurrentElement());

    myList.remove();
    printf("%d\n", myList.getCurrentSize());
/*
    myList.insert(5);
    //printf("Current element: %d\n", myList.getCurrentElement());

    myList.append(6);
    //myList.jumpToNode(2);
    //printf("Current element: %d\n", myList.getCurrentElement());

    printf("Before removing: \n");
    myList.jumpToHead();
    for(int i = 0; i < myList.getCurrentSize(); i++){
        printf("Current element: %d\n", myList.getCurrentElement());
        myList.nextNode();
    }

    myList.jumpToTail();
    myList.remove();

    printf("After removing:\n");
    myList.jumpToHead();
    for(int i = 0; i < myList.getCurrentSize(); i++){
        printf("Current element: %d\n", myList.getCurrentElement());
        myList.nextNode();
    }
*/
	return 0;
}
