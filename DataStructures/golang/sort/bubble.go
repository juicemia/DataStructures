package sort

// Bubble is a simple bubble sort in ascending order.
func Bubble(a []int) []int {
	for i := range a {
		for j := len(a) - 1; j > i; j-- {
			if a[j] < a[j-1] {
				swap(a, j, j-1)
			}
		}
	}

	return a
}
