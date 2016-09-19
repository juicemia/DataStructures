package golang

import "testing"

func TestFind(t *testing.T) {
	tree := DisjointTree{
		DisjointTreeNode{
			Root:  -1,
			Value: 1,
		},
		DisjointTreeNode{
			Root:  -1,
			Value: 2,
		},
		DisjointTreeNode{
			Root:  -1,
			Value: 3,
		},
		DisjointTreeNode{
			Root:  1,
			Value: 4,
		},
	}

	r := tree.Find(0)
	if r != tree[0] {
		t.Errorf("expected find at root to return that root; got %v\n", r)
	}

	t.Logf("disjoint tree: %+v\n", tree)

	r = tree.Find(3)
	if r != tree[1] {
		t.Errorf("expected find at child to return its root; got %v\n", r)
	}
}

func TestSiblings(t *testing.T) {
	tree := DisjointTree{
		DisjointTreeNode{
			Root:  -1,
			Value: 1,
		},
		DisjointTreeNode{
			Root:  0,
			Value: 2,
		},
		DisjointTreeNode{
			Root:  0,
			Value: 3,
		},
		DisjointTreeNode{
			Root:  -1,
			Value: 4,
		},
	}

	s := tree.Siblings(1, 2)
	if !s {
		t.Errorf("expected nodes at 1 and 2 to be siblings; got %v\n", s)
	}

	s = tree.Siblings(1, 3)
	if s {
		t.Errorf("expected nodes at 1 and 3 to not be siblings; got %v\n", s)
	}
}
