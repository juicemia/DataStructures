package sort

// Selection is a simple selection sort in ascending order.
func Selection(a []int) []int {
	for i := range a {
		low := i
		for j := len(a) - 1; j > i; j-- {
			if a[j] < a[j-1] {
				low = j
			}
		}
		swap(a, i, low)
	}

	return a
}
