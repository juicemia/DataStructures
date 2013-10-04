#include "bst.h"

int main() {
	bst_t *ll = malloc(sizeof(bst_t));
	bst_t *ll2 = malloc(sizeof(bst_t));
	tree_add(ll, 10);
	tree_add(ll, 3);
	tree_add(ll, 8);
	tree_add(ll, 15);
	tree_add(ll, 31);
	tree_add(ll, 1);
	tree_add(ll, 12);
	tree_add(ll, 18);
	tree_add(ll, 32);
	tree_add(ll, 25);
	tree_add(ll, 11);
	tree_remove(ll, 10);
	print_tree(ll);

	//printf("%d \n", contains(ll, 4));
	return 0;
}
