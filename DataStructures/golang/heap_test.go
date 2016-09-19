package golang

import "testing"

func TestInsert(t *testing.T) {
	h := &Heap{}

	h.Insert(8)
	if h.arr[0] != 8 {
		t.Errorf("expected h.arr[0] = %v; got %v\n", 8, h.arr[0])
	}

	h.Insert(7)
	if h.arr[0] != 8 {
		t.Errorf("expected small insert to maintain root")
	}

	h.Insert(6)
	if h.arr[0] != 8 {
		t.Errorf("expected small insert to maintain root")
	}

	h.Insert(10)
	if h.arr[0] != 10 {
		t.Errorf("expected large insert to replace root")
	}
}

func TestIsLeaf(t *testing.T) {
	h := &Heap{arr: []int{5}}

	if !h.IsLeaf(0) {
		t.Error("expected h.arr[0] to be a leaf")
	}

	h.Insert(6)
	if !h.IsLeaf(1) {
		t.Error("expected h.arr[1] to be a leaf")
	}

	if h.IsLeaf(0) {
		t.Error("expected the root to not be a leaf anymore")
	}
}

func TestLeftChild(t *testing.T) {
	h := &Heap{arr: []int{5}}

	if h.LeftChild(0) != -1 {
		t.Error("expected the left child of the root to be -1")
	}

	h.Insert(4)
	if h.LeftChild(0) != 1 {
		t.Errorf("expected root's left child to be 1; got %v\n", h.LeftChild(0))
	}
}

func TestRightChild(t *testing.T) {
	h := &Heap{arr: []int{5}}

	if h.RightChild(0) != -1 {
		t.Error("expected the right child of the root to be -1")
	}

	h.Insert(4)
	if h.RightChild(0) != -1 {
		t.Error("expected the right child of the root to be -1")
	}

	h.Insert(3)
	if h.RightChild(0) != 2 {
		t.Error("expected the right child of the root to be at 2")
	}
}

func TestSiftDown(t *testing.T) {
	h := &Heap{arr: []int{5, 6, 7}}

	h.siftDown(0)
	if h.arr[0] == 5 {
		t.Error("expected the root to get sifted down")
	}
}

func TestPop(t *testing.T) {
	h := &Heap{arr: []int{10, 9, 8, 7}}

	top := h.Pop()
	if top != 10 {
		t.Errorf("expected top = %v; got %v\n", 10, top)
	}

	if len(h.arr) != 3 {
		t.Errorf("expected len = 3; got %v\n", len(h.arr))
	}

	top = h.Pop()
	if top != 9 {
		t.Errorf("expected new top value to be 9; got %v\n", top)
	}
}

func TestRemove(t *testing.T) {
	h := &Heap{arr: []int{10, 9, 8, 7}}

	tgt := h.Remove(1)
	if tgt != 9 {
		t.Errorf("expected remove to return target; got %v\n", tgt)
	}

	if h.arr[0] != 10 {
		t.Errorf("expected root to be largest element; got %v\n", h.arr[0])
	}
}
