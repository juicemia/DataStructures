#include "../headers/DoublyLinkedList.h"
#include <cstdio>

int main(int argc, char* argv[])
{
    DoublyLinkedList<int> myList;

    myList.insert(4);

    myList.insert(5);

    myList.append(6);

    printf("Before removing: \n");
    myList.jumpToHead();
    for(int i = 0; i < myList.getCurrentSize(); i++){
        printf("Current element: %d\n", myList.getCurrentElement());
        myList.nextNode();
    }

    myList.jumpToNode(0);
    myList.remove();

    printf("After removing:\n");
    myList.jumpToHead();
    for(int i = 0; i < myList.getCurrentSize(); i++){
        printf("Current element: %d\n", myList.getCurrentElement());
        myList.nextNode();
    }

	return 0;
}
