from random import randint
MAXIMUM = 99999999999
MINIMUM = -1

def dc(A, low, high, count):
    if low <= high:
        if (high == low):
            return A[low], A[high], count
        elif (high-low == 1):
            count += 1
            if (A[high] > A[low]):
                return A[low], A[high], count
            else:
                return A[high], A[low], count
            # return min(A[low], A[high]), max(A[low], A[high]), count
        else:
            mid = int((low+high)/2)
            mi1, ma1, count = dc(A, low, mid, count)
            if mi1 == None:
                mi1 = MAXIMUM
            if ma1 == None:
                ma1 = MINIMUM
            mi2, ma2, count = dc(A, mid+1, high, count)
            if mi2 == None:
                mi2 = MAXIMUM
            if ma2 == None:
                ma2 = MINIMUM
            count += 2
            if mi2 < mi1:
                mi1 = mi2
            if ma2 > ma1:
                ma1 = ma2
            # return min(mi1,mi2), max(ma1,ma2), count
            return mi1, ma1, count


A = [randint(1,100) for x in range(1025)]
count = 0
# print(A)
print(min(A), max(A))
mini, maxi, count = dc(A, 0, len(A)-1, count)
print(mini, maxi, count)