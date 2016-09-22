package sort

import "testing"

func TestMerge(t *testing.T) {
	arr := []int{3, 2, 5, 6, 1, 8}
	sorted := Merge(arr)

	for i := 1; i < len(sorted); i++ {
		if sorted[i] < sorted[i-1] {
			t.Errorf("expected arr to be sorted in ascending order; got %v\n", sorted)
		}
	}

	t.Logf("merged = %v\n", sorted)
}
