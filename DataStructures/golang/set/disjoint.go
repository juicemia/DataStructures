package set

// DisjointTreeNode represents a node in the
// disjoint tree. This tree only needs a pointer
// to the parent node. Two nodes are in the same
// set when they both can be found under the same
// root.
type DisjointTreeNode struct {
	// Root is just the location of the root node
	// in the array holding the sets. If the node
	// itself is a root node, the index is -1.
	Root  int
	Value int
}

// DisjointTree is a tree structure used
// to work with disjoint sets.
type DisjointTree []DisjointTreeNode

// Siblings checks if the nodes at two given locations
// in the disjoint set are in the same set.
func (t DisjointTree) Siblings(i, j int) bool {
	return t.Find(i) == t.Find(j)
}

// Union performs a union of the two disjoint sets
// whose children contain i and j respectively.
func (t *DisjointTree) Union(i, j int) {
	jr := t.flattenAndFind(j)
	_ = t.flattenAndFind(i) // flatten both trees

	(*t)[i].Root = jr
}

// Find returns the root of a node at a given index in
// the array holding the trees.
func (t DisjointTree) Find(i int) DisjointTreeNode {
	for t[i].Root != -1 {
		i = t[i].Root
	}

	return t[i]
}

// This is a special purpose utility function for the
// union. It does the find, but returns the indexes
// instead, as well as flattening both paths to make
// finds in the new set more efficient.
func (t DisjointTree) flattenAndFind(i int) int {
	var path []*DisjointTreeNode

	for t[i].Root != -1 {
		path = append(path, &t[i])
		i = t[i].Root
	}

	for _, n := range path {
		n.Root = i
	}

	return i
}
