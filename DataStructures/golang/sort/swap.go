package sort

func swap(a []int, i, j int) {
	tmp := a[i]
	a[i] = a[j]
	a[j] = tmp
}
