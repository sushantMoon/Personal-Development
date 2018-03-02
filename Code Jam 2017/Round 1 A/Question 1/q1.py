def horizontal_pass(row):
	pseudo = '?'
	size = len(row)
	front = []
	for i in range(size):
		if row[i] == '?':
			front.append(i)
		if row[i] != '?':
			pseudo = row[i]
			if len(front) == 0:
				pass
			else :
				for j in range(len(front)):
					row[front[j]] = pseudo
			front = []
	if len(front) > 0:
		for j in range(len(front)):
			row[front[j]] = pseudo
		front = []
	return row

def vertical_pass(matrix):
	r = len(matrix)
	blank_rows = []
	pseudo_row = []
	for i in range(r):
		if matrix[i][0] == '?':
			blank_rows.append(i)
		if matrix[i][0] != '?':
			pseudo_row = matrix[i]
			if len(blank_rows) == 0:
				pass
			else:
				for j in range(len(blank_rows)):
					matrix[blank_rows[j]] = pseudo_row
				blank_rows = []
	if len(blank_rows) > 0:
		for j in range(len(blank_rows)):
			matrix[blank_rows[j]] = pseudo_row
	return matrix

def cake(matrix):
	r = len(matrix)
	c = len(matrix[0])
	for i in range(r):
		if '?' in matrix[i]:
			matrix[i] = horizontal_pass(matrix[i])
	matrix = vertical_pass(matrix)
	return matrix 

def printanswer(i,answer):
	print "Case #"+str(i)+":"
	for j in range(len(answer)):
		print ''.join(answer[j])

def inputLogic(n):
	n = str(n).split()
	r = int(n[0])
	c = int(n[1])
	matrix = [['?' for i in range(c)] for j in range(r)]
	for i in range(r):
		row = raw_input()
		for j in range(c):
			matrix[i][j] = row[j]
	return matrix

def main():	
	totalTestcases = raw_input()
	for testCase in range(int(totalTestcases)):
		n = raw_input()
		matrix = inputLogic(n)
		answer = cake(matrix)
		printanswer(testCase+1,answer)


if __name__ == '__main__':
	main()