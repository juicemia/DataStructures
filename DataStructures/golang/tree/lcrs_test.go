package tree

import "testing"

func TestIsLeaf(t *testing.T) {
	tree := General{
		Node{
			Parent:       -1,
			LeftChild:    1,
			RightSibling: -1,
			Value:        0,
		},
		Node{
			Parent:       0,
			LeftChild:    -1,
			RightSibling: 2,
			Value:        1,
		},
		Node{
			Parent:       0,
			LeftChild:    -1,
			RightSibling: 3,
			Value:        2,
		},
		Node{
			Parent:       0,
			LeftChild:    -1,
			RightSibling: -1,
			Value:        3,
		},
	}

	l := tree[3].IsLeaf()
	if !l {
		t.Error("expected last node in tree to be a leaf")
	}

	l = tree[0].IsLeaf()
	if l {
		t.Errorf("expected the root of the tree to not be a leaf")
	}
}

func TestAddChild(t *testing.T) {
	tree := General{
		Node{
			Parent:       -1,
			LeftChild:    1,
			RightSibling: -1,
			Value:        0,
		},
		Node{
			Parent:       0,
			LeftChild:    -1,
			RightSibling: 2,
			Value:        1,
		},
		Node{
			Parent:       0,
			LeftChild:    -1,
			RightSibling: 3,
			Value:        2,
		},
		Node{
			Parent:       0,
			LeftChild:    -1,
			RightSibling: -1,
			Value:        3,
		},
	}

	// These tests aren't exactly the best, but they're more
	// for me to play with functionality and just make sure
	// that everything is more or less working. Real unit tests
	// probably shouldn't be so brittle.
	tree = tree.AddChild(3, 4)
	if len(tree) != 5 {
		t.Errorf("expected node to be added to tree array")
	}

	if tree[4].Parent != 3 {
		t.Errorf("expected new child to have the correct parent")
	}

	tree = tree.AddChild(0, 5)
	if tree[5].Parent != 0 {
		t.Errorf("expected root's child to have the root as its parent; got %v\n", tree[5].Parent)
	}
}
