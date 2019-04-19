"""
Sushant 
Date 12/8/2018
Minimum Adjacent Swaps for pushing smallest and the largest values to the corners of the array
Reference : 
https://www.geeksforgeeks.org/minimum-adjacent-swaps-to-move-maximum-and-minimum-to-corners/
"""

from collections import defaultdict


def minimum_swaps(a):
    d = defaultdict(list)
    mini = 0
    maxi = 0
    for i in range(len(a)):
        # corners are 0 and len(a)-1
        d[str(a[i])].append(i)
        if i == 0:
            mini = a[i]
            maxi = a[i]
        if a[i] < mini:
            mini = a[i]
        elif a[i] > maxi:
            maxi = a[i]
    mini_max = max(d[str(mini)])
    maxi_min = min(d[str(maxi)])
    if (mini_max < maxi_min):
        count = (len(a) - 1 - mini_max) + maxi_min - 1
    else:
        count = (len(a) - 1 - mini_max) + maxi_min
    return count

def main():
    a = [3, 1, 5, 3, 5, 5, 2]
    print(minimum_swaps(a))

main()
