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
	//heap_add(ll, 15);
	//heap_add(ll, 87);
	//heap_add(ll, 12);
	//heap_add(ll, 32);
	print_tree(ll);

	//printf("%d \n", contains(ll, 4));
	return 0;
}
