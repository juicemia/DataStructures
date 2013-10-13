#!/usr/bin/python

# Please read 1D_peak_finding.pdf for explanation what a peak is, proofs, and asymptotic complexity analysis of the algorithms

# There will be two algorithms. A simple iteration through all the items in the array until finding a peak,
# and a divide and conquer approach to finding a peak

# Keep in mind, both of the algorithms find a peak, not all the peaks
def find_peak_greedy(array):
	try:
		size = len(array);
	except:
		# array is empty
		return None

	if (size == 1 or array[0] >= array[1]): # array is of size one, or the first element is a peak
		return array[0] # since it's of size 1, 
	elif (array[size - 1] >= array[size - 2]): # last element is a peak
		return array[size - 1]
	else:
		# Iterate through array items one by one
		for i in range(size):
			# make sure it doesn't run out of bounds
			if (i < size - 1 and i > 0 and (array[i] >= array[i-1] and array[i] >= array[i+1])):
				return array[i] 

def find_peak_recursive(array, low, high):
	n = int((low + high)/2)

	# make sure that index is not out of bounds
	if (n > 0 and array[n] < array[n-1]): # look at the left side of the array
		return find_peak_recursive(array, low, n)
	elif (n < len(array) - 1 and array[n] < array[n+1]): # look at the right side of the array
		return find_peak_recursive(array, n, high)
	else: # a peak, since array[n-1] <= array[n] <= array[n+1]
		return array[n]
#array = (1, 10, 15, 120, -5, -100, 150, 879, 10, 77)

# Answers might differ from the two functions because they approach the problem differently
# However, both answers will be peaks.

#print "%d" % find_peak_greedy(array)
#print "%d" % find_peak_recursive(array, 0, len(array))
