package sort

import "testing"

func TestInsertion(t *testing.T) {
	arr := []int{3, 2, 5, 6}

	sorted := Insertion(arr)

	for i, v := range sorted {
		if v > sorted[i] {
			t.Errorf("expected arr to be sorted in ascending order; got %v\n", arr)
		}
	}
}
