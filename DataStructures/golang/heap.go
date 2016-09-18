package golang

// Heap is a max-heap of integers. Since
// heaps can be created as arrays, the type
// only needs to be an alias of []int with
// the heap methods attached to it.
type Heap struct {
	arr []int
}

// Insert inserts an element into the array
// and returns the index at which it was inserted.
func (h *Heap) Insert(elem int) int {
	h.arr = append(h.arr, elem)

	curr := len(h.arr) - 1

	for curr != 0 && h.arr[h.Parent(curr)] < h.arr[curr] {
		h.swap(curr, h.Parent(curr))
		curr = h.Parent(curr)
	}

	return curr
}

func (h *Heap) swap(i, j int) {
	tmp := h.arr[i]
	h.arr[i] = h.arr[j]
	h.arr[j] = tmp
}

// Parent returns the index of the parent
// for the element at the given pos in the array.
func (h *Heap) Parent(pos int) int {
	return (pos - 1) / 2
}
