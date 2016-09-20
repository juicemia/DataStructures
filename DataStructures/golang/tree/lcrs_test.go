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
