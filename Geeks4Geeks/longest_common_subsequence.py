"""
 * Author Sushant Moon
 * Email sushant.moon@gmail.com
 * Create date 2018-08-15 08:08:37
 * Modify date 2018-08-15 08:08:37
 * Description Longest common subsequence (https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0/)
"""

def lcs(a,b,la,lb):
    l = [[None]*la for i in range(lb)]
    for i in range(lb):
        for j in range(la):
            if b[i] == a[j]:
                if ((i == 0) or (j == 0)):
                    l[i][j] = 1
                else:
                    l[i][j] = 1 + l[i-1][j-1]
            else:
                top = 0
                left = 0
                if (i > 0):
                    top = l[i-1][j]
                if (j > 0):
                    left = l[i][j-1]
                l[i][j] = max(top, left)
    # print(l)
    return l[lb-1][la-1]

def main():
    t = int(input().strip())
    while(t>0):
        j = input()
        [la, lb] = [int(x.strip()) for x in j.split()]
        a = input()
        b = input()
        print(lcs(a,b,la,lb))
        t -= 1
main()