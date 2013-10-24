#include "heap.h"

int main() {
	heap_t *ll = malloc(sizeof(heap_t));
	heap_t *ll2 = malloc(sizeof(heap_t));
	heap_add(ll, 10);
	heap_add(ll, 11);
	heap_add(ll, 9);
	heap_add(ll, 5);
	heap_add(ll, 18);
	heap_add(ll, 7);
	heap_add(ll, 15);
	heap_add(ll, 87);
	heap_add(ll, 12);
	heap_add(ll, 32);
	heap_add(ll, 48);
	heap_add(ll, 799);
	print_heap(ll, 2);
	puts("\n\n\n");
	heap_remove(ll, 799);
	heap_remove(ll, 7);
	heap_remove(ll, 48);
	heap_remove(ll, 10);
	heap_remove(ll, 11);
	heap_remove(ll, 9);
	print_heap(ll, 2);

	//printf("%d \n", contains(ll, 4));
	return 0;
}
