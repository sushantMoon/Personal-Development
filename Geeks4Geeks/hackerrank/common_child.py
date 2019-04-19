"""
 * Author Sushant Moon
 * Email sushant.moon@gmail.com
 * Create date 2018-08-16 01:19:00
 * Modify date 2018-08-16 01:19:00
 * Description longest common subsequence => hackerrank/interview prep kit/string/common child
 https://www.hackerrank.com/challenges/common-child/problem
"""


#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the commonChild function below.
def commonChild(s1, s2):
    ls1 = len(s1)
    ls2 = len(s2)
    currow = []
    prevrow = []
    for i in range(ls2):
        prevrow = currow
        currow = [0 for x in range(ls2)]
        for j in range(ls1):
            if s2[i] == s1[j]:
                if ((i == 0) or (j == 0)):
                    currow[j] = 1
                else:
                    currow[j] = 1 + prevrow[j-1]
            else:
                top = 0
                left = 0
                if (i > 0):
                    top = prevrow[j]
                if (j > 0):
                    left = currow[j-1]
                if top > left:
                    currow[j] = top
                else:
                    currow[j] = left
    return currow[-1]

if __name__ == '__main__':

    s1 = input()

    s2 = input()

    result = commonChild(s1, s2)

    print(result)
