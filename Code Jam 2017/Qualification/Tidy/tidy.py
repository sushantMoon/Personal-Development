def tidy(number):
	convert = False
	if len(number) == 1:
		return int(''.join([str(x) for x in number]))
	else :
		pos = 0
		lastpos = 0
		while (pos < len(number)):
			if convert == False:
				if pos == len(number)-1:
					return long(''.join([str(x) for x in number]))
				if number[pos] < number[pos+1]:
					lastpos = pos + 1
				elif number[pos] == number[pos+1]:
					if number[lastpos] == number[pos]:
						pass
					else:
						lastpos = pos
				else:
					number[lastpos] -= 1
					pos = lastpos
					convert = True
			else :
				number[pos] = 9
			pos += 1
		return long(''.join([str(x) for x in number]))

def printanswer(i,n):
	print "Case #"+str(i)+": "+str(n)

def inputLogic(n):
	n = str(n)
	array = [int(x) for x in n]
	return array

def main():	
	totalTestcases = raw_input()
	for testCase in range(int(totalTestcases)):
		n = raw_input()
		number = inputLogic(n)
		answer = tidy(number)
		printanswer(testCase+1,answer)


if __name__ == '__main__':
	main()