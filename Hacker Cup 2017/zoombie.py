import itertools
from pprint import pprint
def main():
	tests = raw_input()
	for i in range(int(tests)):
		values = [int(temp) for temp in raw_input().split(" ")]
		health = values[0]
		spells = values[1]
		print "health: ", health, "spells : ", spells
		probablity = 0.0
		spellList = [temp for temp in raw_input().split(" ")]
		print spellList
		spellDict = {}
		for j in range(len(spellList)):
			spell = spellList[j]
			a = spell.split('d')
			x = int(a[0])
			y = 0
			z = 0
			if '+' in a[1]:
				y = int(a[1].split('+')[0])
				z = int(a[1].split('+')[1])
			elif '-' in a[1]:
				y = int(a[1].split('-')[0])
				z = -1 * int(a[1].split('-')[1])
			else:
				y = int(a[1])
				z = 0
			print "x:",x,"y:",y,"z:",z
			diceValues = [int(temp)+1 for temp in range(y)]
			spellPower = [p for p in itertools.product(diceValues, repeat=x)]
			# spellDict[spellList[j]] = {}
			pprint(spellPower)
		# break




main()