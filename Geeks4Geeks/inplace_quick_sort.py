"""
 * Author Sushant Moon
 * Email sushant.moon@gmail.com
 * Create date 2018-07-19 12:29:34
 * Modify date 2018-07-19 12:29:34
 * Description QUick Sort Inplace As discussed in the class of 19 July 2018, Probability and Stochastic Processes
"""
from random import randint

def swap(A, i , j):
    A[i], A[j] = A[j], A[i]

def split(A, low, high):
    k = randint(low, high)
    swap(A, low, k)
    w = low
    i = low
    for j in range(low+1, high+1):
        if A[j] < A[w]:
            i += 1
            if (i != j):
                swap(A, i, j)
    swap(A, i, w)
    w = i
    return A, w

def quick_sort(A, low, high):
    if low < high:
        A, w = split(A, low, high)
        # w is the position of the pivot along which A is split in two parts 
        # all elements in the position less than w are less than A[w] 
        # all elements in the position greater than w are greater than A[w]
        A = quick_sort(A, low, w-1)
        A = quick_sort(A, w+1, high)
    return A


size = 9
A = [randint(0,9) for i in range(size)]
print(A)
print(quick_sort(A, 0, size-1))