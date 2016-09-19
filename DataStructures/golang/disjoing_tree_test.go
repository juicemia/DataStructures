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
		DisjointTreeNode{
			Root:  3,
			Value: 5,
		},
	}

	r := tree.Find(0)
	if r != tree[0] {
		t.Errorf("expected find at root to return that root; got %v\n", r)
	}

	r = tree.Find(3)
	if r != tree[1] {
		t.Errorf("expected find at child to return its root; got %v\n", r)
	}

	r = tree.Find(4)
	if r != tree[1] {
		t.Errorf("expected find at leaf to return its root; got %v\n", r)
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

func TestUnion(t *testing.T) {
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
		DisjointTreeNode{
			Root:  2,
			Value: 5,
		},
	}

	tree.Union(3, 4)
	if tree[3].Root != tree[4].Root {
		t.Errorf("expected nodes at 3 and 4 to be united\n\ntree[3] = %+v\ntree[4] = %+v\n", tree[3], tree[4])
	}
}
