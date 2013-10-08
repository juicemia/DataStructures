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
    //myList.jumpToNode(2);
    //printf("Current element: %d\n", myList.getCurrentElement());

    myList.jumpToTail();
    for(int i = myList.getCurrentSize() - 1; i >= 0; i--){
        printf("Current element: %d\n", myList.getCurrentElement());
        myList.prevNode();
    }

	return 0;
}
