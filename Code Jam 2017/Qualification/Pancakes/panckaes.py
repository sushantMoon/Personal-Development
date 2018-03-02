def flipper(line,k):
	count = 0
	pos = 0
	while(pos < len(line)):
		if line[pos] == '+':
			pos += 1
		else:
			if line[pos] == '-':
				count += 1
				for i in range(k):
					value = pos + i
					if value >= len(line):
						return "IMPOSSIBLE"
					elif line[value] == '-':
						line[value] = '+'
					else:
						line[value] = '-'
	return count



def printanswer(i,n):
	print "Case #"+str(i)+": "+str(n)

def main():	
	totalTestcases = raw_input()
	for testCase in range(int(totalTestcases)):
		n = raw_input().split()
		line = [x for x in n[0]]
		k = int(n[1])
		answer = flipper(line,k)
		printanswer(testCase+1,answer)


if __name__ == '__main__':
	main()