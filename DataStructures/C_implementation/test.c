#include "heap.h"

int main() {
	heap_t *ll = malloc(sizeof(heap_t));
	heap_t *ll2 = malloc(sizeof(heap_t));
	heap_add(ll, 10);
	heap_add(ll, 11);
	heap_add(ll, 9);
	print_tree(ll);

	//printf("%d \n", contains(ll, 4));
	return 0;
}
