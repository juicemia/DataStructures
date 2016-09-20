package tree

// Node represents a node in the tree. This
// tree is technically a binary tree. A useful
// property of all trees is that they can in fact
// be represented as binary trees. The node's left
// child is the leftmost child, while the right child
// is just the node's right sibling. Also a location
// for the parent is retained.
type Node struct {
	LeftChild    int
	RightSibling int
	Parent       int

	Value int
}

// IsLeaf returns true if the node is a leaf of the tree.
func (n Node) IsLeaf() bool {
	return n.LeftChild == -1
}

// General represents a general tree structure, with no restrictions
// on the number of children. It's stored as an array for memory
// efficiency and to leverage caches and locality of reference, as
// opposed to linked list implementations.
type General []Node

// AddChild adds a child to the given node.
func (t General) AddChild(n *Node, elem int) Node {
	lastChild := t[n.LeftChild]

	for lastChild.RightSibling != -1 {
		lastChild = t[lastChild.RightSibling]
	}

	t = append(t, Node{
		LeftChild:    -1,
		RightSibling: -1,
		Parent:       lastChild.Parent,
		Value:        elem,
	})

	return t[len(t)-1]
}
