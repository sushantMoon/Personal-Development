def main():
	tests = raw_input()
	for i in range(int(tests)):
		n = raw_input()
		items = []
		for j in range(int(n)):
			value = raw_input()
			items.append(int(value))
		items.sort()
		lower = -1
		higher = len(items) - 1
		trips = 0
		# print items
		# print items,lower, higher
		higherWeight = items[higher]
		weight = higherWeight
		# bag = []
		# bag.append(higherWeight)
		while lower < higher:
			if weight < 50 :
				lower = lower + 1
				# bag.append(items[lower])
				weight = weight + higherWeight
			else :
				# print bag
				# bag = []
				higher = higher - 1
				higherWeight = items[higher]
				# bag.append(higherWeight)
				weight = higherWeight
				trips = trips + 1
		print "Case #"+str(i+1)+": "+str(trips)


main()