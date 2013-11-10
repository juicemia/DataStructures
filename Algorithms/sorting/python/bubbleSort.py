#!/bin/python

def bubbleSort(array):
	# a flag
	swapped = False
	
	while True: # a simulation of do-while loop in python
		swapped = False
		for i in range(1, len(array)):
			if (array[i] < array[i-1]):
				# typical swap procedure
				temp = array[i]
				array[i] = array[i-1]
				array[i-1] = temp
				swapped = True
		if not swapped:
			break
			
def printArray(ar):
	for i in range(len(ar)):
		print "%d, " % ar[i]

ar = [0,13,4,53,64,2,645, 132]
bubbleSort(ar)
printArray(ar)