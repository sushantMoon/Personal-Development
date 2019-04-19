"""
 * Author Sushant Moon
 * Email sushant.moon@gmail.com
 * Create date 2018-08-15 05:44:33
 * Modify date 2018-08-15 05:44:33
 * Description: Longest increasing substring (https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/) 
https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
"""

def lis(a):
    n = len(a)
    l = [1]*n
    for i in range(1,n):
        for j in range(0,i):
            if (a[i] > a[j]) and (l[j]+1 > l[i]):
                l[i] = l[j]+1

    m = 0
    for i in l:
        m = max(m, i)
    return m 

# a = [10, 22, 9, 33, 21, 50, 41, 60]
# print(lis(a))

def main():
    t = int(input().strip())
    for i in range(t):
        j = input()
        k = input().split()
        print(lis([int(x.strip()) for x in k]))

main()