package sort

import "fmt"

func Merge(a []int) []int {
	merge(a, []int{}, 0, len(a)-1)

	return a
}

func merge(a, tmp []int, left, right int) {
	fmt.Printf("left = %v\n", left)
	fmt.Printf("right = %v\n", right)
	if left == right {
		return
	}

	mid := (left + right) / 2
	fmt.Printf("mid = %v\n", mid)

	merge(a, tmp, left, mid)
	merge(a, tmp, mid+1, right)

	for _, v := range a {
		tmp = append(tmp, v)
	}

	fmt.Printf("tmp = %v; a = %v\n", tmp, a)

	li := left
	ri := mid + 1

	for i := left; i <= right; i++ {
		fmt.Printf("li = %v; ri = %v\n", li, ri)
		switch {
		case li == mid+1:
			a[i] = tmp[ri]
			ri++
		case ri > right:
			a[i] = tmp[li]
			li++
		case tmp[li] < tmp[ri]:
			a[i] = tmp[li]
			li++
		case tmp[ri] < tmp[li]:
			a[i] = tmp[ri]
			ri++
		}
	}
}
