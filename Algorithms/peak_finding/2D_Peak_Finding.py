#!/usr/bin/python

# Please read 2D_peak_finding.pdf asymptotic complexity analysis of the algorithms
# There will be at least three algorithms

# Keep in mind, all of the algorithms find a peak, not all the peaks

# Declare global because python being pain and wouldn't let import regularly
# since the filename starts with a number
one_dim_find = __import__('1D_Peak_Finding')

# Greedy approach will just iterate through all the items in the array, until the
# peek is found
def find_2D_peak_greedy(array_2d):
	try:
		rows = len(array_2d);
		cols = len(array_2d[1]);
	except:
		# array is empty, or it's a 1D array
		return None
	else:
		# case where each array is only one component
		if (cols == 1): 
			temp_array = []
			for i in range(rows):
				temp_array.append(array_2d[i][0])
			return one_dim_find.find_peak_recursive(temp_array, 0, len(temp_array))
	for i in range(rows):
		for j in range(cols):
			# first row
			if (i == 0):
				if (j == 0): # first element
					if (array_2d[0][0] >= array_2d[0][1] and array_2d[0][0] >= array_2d[1][0]):
						return array_2d[i][j]
				elif (j == cols - 1): # last element of the row
					if (array_2d[0][cols - 1] >= array_2d[0][cols - 2] and array_2d[0][cols - 1] >= array_2d[1][cols - 1]):
						return array_2d[i][j]
				else:
					if(array_2d[0][j] >= array_2d[0][j - 1] and array_2d[0][j] >= array_2d[0][j + 1] and array_2d[0][j] >= array_2d[1][j]):
						return array_2d[i][j]
			elif (i == rows - 1): # last row
				if (j == 0): # first element of the last row
					if (array_2d[i][0] >= array_2d[i][1] and array_2d[i][0] >= array_2d[i - 1][0]):
						return array_2d[i][j]
				elif (j == cols - 1): # last element of the row
					if (array_2d[i][cols - 1] >= array_2d[i][cols - 2] and array_2d[i][cols - 1] >= array_2d[i -1][cols - 1]):
						return array_2d[i][j]
				else:
					if(array_2d[i][j] >= array_2d[i][j - 1] and array_2d[i][j] >= array_2d[i][j + 1] and array_2d[i][j] >= array_2d[i-1][j]):
						return array_2d[i][j]
			else: 	# anywhere else in the array
				if (j == 0): # first column
					if (array_2d[i][j] >= array_2d[i][j+1] and array_2d[i][j] >= array_2d[i-1][j] and array_2d[i][j] >= array_2d[i+1][j]):
						return array_2d[i][j]
				elif (j == cols - 1): # last column
					if (array_2d[i][j] >= array_2d[i][j-1] and array_2d[i][j] >= array_2d[i-1][j] and array_2d[i][j] >= array_2d[i+1][j]):
						return array_2d[i][j]
				elif (array_2d[i][j] >= array_2d[i][j+1] and array_2d[i][j] >= array_2d[i][j-1] and array_2d[i][j] >= array_2d[i+1][j] and array_2d[i][j] >= array_2d[i-1][j]):
						return array_2d[i][j]


# In this approach, first I find the maximum element of the middle column j,
# and then, in the row i, which the maximum element belongs to, I try to see if there is a peak there.
# If not then recurse until the peak is found
def find_2D_peak_recMax(array_2d, low, high):
	
	# Rows of the 2D array
	rows = len(array_2d)
	# Middle column in between the low and high columns
	mid_col = int((low + high)/2) - 1
	print "%d" % mid_col
	# Declare temporary max index to be the first element of the column
	max = 0
	
	# Find the maximum value in the column
	for i in range(rows):
			max = max if max > array_2d[i][mid_col] else i
	
	# Edge cases
	if (mid_col == 0 or mid_col == rows - 1):
		return array_2d[max][mid_col]

	if (array_2d[max][mid_col] <= array_2d[max][mid_col - 1]): # go to the left
		return find_2D_peak_recMax(array_2d, low, mid_col)
	elif (array_2d[max][mid_col] <= array_2d[max][mid_col + 1]): # go to the right
		return find_2D_peak_recMax(array_2d, mid_col, high)
	return array_2d[max][mid_col] # jackpot
	

array = ((1, 10, 15, 120, -5, -100, 150, 879, 10, 77), (1, 10, 15, 120, -5, -100, 150, 879, 10, 77), (1, 10, 15, 120, -5, -100, 150, 879, 10, 77))
#array = ((1, ), (2, ), (3, ))
# Answers might differ from the two functions because they approach the problem differently
# However, both answers will be peaks.
print "%d" % find_2D_peak_greedy(array)
print "%d" % find_2D_peak_recMax(array, 0, len(array[0]))
