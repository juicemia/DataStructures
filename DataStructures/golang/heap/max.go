package heap

// Max is a max-heap of integers. Since
// heaps can be created as arrays, the type
// only needs to be an alias of []int with
// the heap methods attached to it.
type Max struct {
	arr []int
}

// Insert inserts an element into the array
// and returns the index at which it was inserted.
func (h *Max) Insert(elem int) int {
	h.arr = append(h.arr, elem)

	curr := len(h.arr) - 1

	for curr != 0 && h.arr[h.Parent(curr)] < h.arr[curr] {
		h.swap(curr, h.Parent(curr))
		curr = h.Parent(curr)
	}

	return curr
}

func (h *Max) swap(i, j int) {
	tmp := h.arr[i]
	h.arr[i] = h.arr[j]
	h.arr[j] = tmp
}

// Parent returns the index of the parent
// for the element at the given pos in the array.
func (h *Max) Parent(pos int) int {
	return (pos - 1) / 2
}

func (h *Max) Pop() int {
	elem := h.arr[0]

	h.swap(0, len(h.arr)-1)
	h.arr = h.arr[:len(h.arr)-1]

	h.siftDown(0)
	return elem
}

func (h *Max) siftDown(pos int) {
	for !h.IsLeaf(pos) {
		j := h.LeftChild(pos)
		rc := h.RightChild(pos)

		if rc > 0 && h.arr[rc] > h.arr[j] {
			j = rc
		}

		if h.arr[pos] > h.arr[j] {
			return
		}

		h.swap(pos, j)
		pos = j
	}
}

// IsLeaf determines whether the element
// at the given position is a leaf of the
// tree.
func (h *Max) IsLeaf(pos int) bool {
	n := len(h.arr)

	return pos >= n/2 && pos < n
}

// LeftChild returns the index where the
// given position's left child is at, or
// -1 if that position would be outside
// the bounds of the array.
func (h *Max) LeftChild(pos int) int {
	idx := 2*pos + 1

	if idx >= len(h.arr) {
		return -1
	}

	return idx
}

// RightChild returns the index where the
// given position's right child is at, or
// -1 if that position would be outside
// the bounds of the array
func (h *Max) RightChild(pos int) int {
	idx := 2*pos + 2

	if idx >= len(h.arr) {
		return -1
	}

	return idx
}

func (h *Max) Remove(pos int) int {
	h.swap(pos, len(h.arr)-1)

	elem := h.arr[len(h.arr)-1]

	for pos != 0 && h.arr[pos] > h.arr[h.Parent(pos)] {
		h.swap(pos, h.Parent(pos))

		pos = h.Parent(pos)
	}

	h.arr = h.arr[:len(h.arr)-1]

	h.siftDown(0)

	return elem
}
