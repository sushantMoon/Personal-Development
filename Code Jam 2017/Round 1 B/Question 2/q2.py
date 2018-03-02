
def printanswer(i,answer):
	print "Case #"+str(i)+": "+str(answer)

def colorWheel(n,r,y,b):
	answer = ''
	count = 0
	while (True):
		if r > 0:
			if answer == '':
				answer = 'R'
				r -= 1
			elif answer[-1] != 'R' : 
				if b != 0 or y != 0 or answer[0] != 'R':
					answer += 'R'
					r -= 1
				else : 
					# return 'IMPOSSIBLE'
					pass
			else :
				pass
		if y > 0:
			if answer == '':
				answer = 'Y'
				y -= 1
			elif answer[-1] != 'Y' : 
				if b != 0 or r != 0 or answer[0] != 'Y':
					answer += 'Y'
					y -= 1
				else : 
					# return 'IMPOSSIBLE'
					pass
			else :
				pass
		if b > 0:
			if answer == '':
				answer = 'B'
				b -= 1
			elif answer[-1] != 'B' : 
				if r != 0 or y != 0 or answer[0] != 'B':
					answer += 'B'
					b -= 1
				else : 
					# return 'IMPOSSIBLE'
					pass
			else :
				pass
		if r == 0 and y == 0 and b == 0 :
			return answer
		count += 1
		if count > n:
			return 'IMPOSSIBLE'



def main():	
	totalTestcases = raw_input()
	for testCase in range(int(totalTestcases)):
		line = [int(x) for x in raw_input().split()]
		n = line[0]
		r = line[1]
		y = line[3]
		b = line[5]
		answer = colorWheel(n,r,y,b)
		printanswer(testCase+1,answer)


if __name__ == '__main__':
	main()