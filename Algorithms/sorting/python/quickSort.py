#!/usr/bin/python

def quickSort(array):
	left, right, pivots = [], [], []
	
	if len(array) > 1:
		pivot = len(array) / 2
		for i in range(len(array)):
		
			if array[pivot] > array[i]:
				left.append(array[i])
			elif array[pivot] < array[i]:
				right.append(array[i])
			else:
				pivots.append(array[i])
		left = quickSort(left)
		right = quickSort(right)

		# make the array
		array = []
		array.extend(left)
		array.extend(pivots)
		array.extend(right)
		
		return array
	else:
		return array
				

def printArray(ar):
	for i in range(len(ar)):
		print "%d, " % ar[i]

ar = [0,13,4,53,64,2,645, 132]

ar = quickSort(ar)
printArray(ar)