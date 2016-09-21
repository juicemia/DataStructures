package sort

import "testing"

func TestBubble(t *testing.T) {
	arr := []int{3, 2, 5, 6}

	sorted := Bubble(arr)

	for i, v := range sorted {
		if v > sorted[i] {
			t.Errorf("expected arr to be sorted in ascending order; got %v\n", arr)
		}
	}

	t.Logf("bubble = %v\n", sorted)
}
