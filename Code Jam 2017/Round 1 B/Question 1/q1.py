
def printanswer(i,answer):
	print "Case #"+str(i)+": %.6f"%answer

def main():	
	totalTestcases = raw_input()
	for testCase in range(int(totalTestcases)):
		line = raw_input().split()
		d = float(line[0])
		n = int(line[1])
		time = 0
		for i in range(n):
			pos = raw_input().split()
			pos[0] = float(pos[0])
			pos[1] = float(pos[1])
			if d > pos[0]:
				requiredTime = ((d - pos[0])/pos[1])
				if requiredTime > time:
					time = requiredTime
			else :
				pass
		printanswer(testCase+1,float(d/time))


if __name__ == '__main__':
	main()