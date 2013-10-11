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

array = ((1, 10, 15, -1000), (3, 9, 189, 791), (79, 791, 56, 189))

# Answers might differ from the two functions because they approach the problem differently
# However, both answers will be peaks.
print "%d" % find_2D_peak_greedy(array)
