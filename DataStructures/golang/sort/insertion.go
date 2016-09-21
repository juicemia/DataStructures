package sort

// Insertion is a basic insertion sort in ascending order.
func Insertion(a []int) []int {
	for i := range a {
		for j := i; j > 0 && a[j] < a[j-1]; j-- {
			swap(a, j, j-1)
		}
	}

	return a
}