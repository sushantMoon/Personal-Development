"""
 * Author Sushant Moon
 * Email sushant.moon@gmail.com
 * Create date 2018-08-15 05:22:01
 * Modify date 2018-08-15 05:22:01
 * Description : Hacker rank/Interview prep kit/max array sum
 https://www.hackerrank.com/challenges/max-array-sum?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dynamic-programming
"""

import math
import os
import random
import re
import sys

# Complete the maxSubsetSum function below.
def maxSubsetSum(arr):
    n = len(arr)
    maxi = 0
    l = arr
    m = 0
    for i in range(2,n):
        if (i-3>=0):
            if(l[i-3]>l[i-2]):
                m = l[i-3]
            else:
                m = l[i-2]
            if (m < 0):
                if l[i] < m:
                    l[i] = m
            else:
                if l[i] < 0:
                    l[i] = m
                else:
                    l[i] = l[i]+m 
        else:
            if (i-2>=0):
                if(0>l[i]):
                    if l[i] < l[i-2]:
                        l[i] = l[i-2]
                else:
                    if (l[i]+l[i-2] > l[i]):
                        l[i] = l[i]+l[i-2]            
        # print(l)    
    for i in l:
        maxi = max(i,maxi)
    return maxi
            
if __name__ == '__main__':
    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    res = maxSubsetSum(arr)

    print(res)