#!/usr/bin/python

def mergeSort(array, bottom, top):
	if (top - bottom) < 2:
		return
	mid = (bottom + top) / 2
	
	#recursion
	mergeSort(array, bottom, mid)
	mergeSort(array, mid, top)
	merge(array, bottom, mid, top)
	
def merge(ar, bottom, middle, top):

	# temporary variables
	size1 = middle - bottom
	size2= top - middle
	left = []
	right = []

	l = 0 # counter for left
	r = 0 # counter for right
	
	for i in range(size1):
		left.append(ar[bottom + i])
	for i in range(size2):
		right.append(ar[middle + i])
	i = bottom
	while (i < top and l < len(left) and r < len(right)):
		if (left[l] > right[r]):
			ar[i] = left[l]
			l+=1
			
			# we're done with the left array, we can just recopy right
			if l == size1:
				for j in range(r, size2):
					i+=1
					ar[i] = right[j]
				break
		else:
			ar[i] = right[r]
			r+=1
			
			if r == size2:
				for j in range(l, size1):
					i+=1
					ar[i] = left[j]
				break
		i+=1
	

def printArray(ar):
	for i in range(len(ar)):
		print "%d, " % ar[i]

ar = [0,13,4,53,64,2,645, 132]

mergeSort(ar, 0, len(ar))
printArray(ar)