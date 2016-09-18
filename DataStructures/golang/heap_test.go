package golang

import "testing"

func TestInsert(t *testing.T) {
	h := &Heap{}

	h.Insert(8)
	if h.arr[0] != 8 {
		t.Fatalf("expected h.arr[0] = %v; got %v\n", 8, h.arr[0])
	}

	h.Insert(7)
	if h.arr[0] != 8 {
		t.Fatalf("expected small insert to maintain root")
	}

	h.Insert(6)
	if h.arr[0] != 8 {
		t.Fatalf("expected small insert to maintain root")
	}

	h.Insert(10)
	if h.arr[0] != 10 {
		t.Fatalf("expected large insert to replace root")
	}
}
