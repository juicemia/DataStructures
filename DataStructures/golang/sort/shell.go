package sort

// Shell provides a shell sort implementation like the
// one in the book.
func Shell(a []int) []int {
	for i := len(a) / 2; i > 2; i /= 2 {
		for j := 0; j < i; j++ {
			shellInsertion(a[j:], i)
		}
	}

	shellInsertion(a, 1)

	return a
}

func shellInsertion(a []int, inc int) []int {
	for i := inc; i < len(a); i += inc {
		for j := i; j >= inc && a[j] < a[j-1]; j -= inc {
			swap(a, j, j-inc)
		}
	}

	return a
}
