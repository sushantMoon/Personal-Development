
def insertion_sort(a):
    for i in range(len(a)):
        j = i
        while ((j>0) and (a[j-1]>a[j])):
            a[j-1], a[j] = a[j], a[j-1]
            j -= 1
    return a


a = [1,2,3,4,5,4,3,2,4,1]
print(insertion_sort(a))