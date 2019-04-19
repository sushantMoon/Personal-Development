"""
 * Author Sushant Moon
 * Email sushant.moon@gmail.com
 * Create date 2018-07-31 12:51:53
 * Modify date 2018-07-31 12:51:53
 * Description : Problem TACHSTCK from Codechef

Basically after sorting we can check for consequtive elements if they are the range.
The maths given below will prove that this mehtod will always satisfy the optimal match. 

Maths in the problem:
Given:
-D <= l1 - lm <= D  ......... 1
-D <= l2 - ln <= D  ......... 2
-D <= l1 - l2 <= D  ......... 3
l1 <= l2            ......... 4
To prove:
-D <= ln - lm <= D

Proof:

Equation 1 can changed to 
-D -l1 +ln <= ln - lm <= D -l1 + ln     .............5

Equation 2 can changed to 
-D -l2 +l1 <= l1 - ln <= D -l2 + l1     .............6
-D + (l1 - l2) <= l1 - ln <= D + (l1 - l2)     .............7
In equation 7 max and min value of l1 - l2 is -D and D respectively
hence on substituting the values, adding lowest value in the lower bound, the equation would still hold
similarly adding highest possible value of l1 - l2 in upper bound will increase it which will be higher
than all the possible values, hence inequality would still hold.

-D + (-D) <= l1 - ln <= D + (D)     .............8
-2D <= l1 - ln <= 2D     .............9

Using the same logic as metioned after 7, substituting the values correspondingly in the equation 5,
-D - (l1 -ln) <= ln - lm <= D - (l1 -ln)     .............10
-D - (-2D) <= ln - lm <= D - (2D)     .............11
D <= ln - lm <= -D     .............11

hence proved
"""
# import pdb

def main(): 
    a = input()
    [n, D] = [int(x) for x in a.split()]
    l = list()
    for i in range(n):
        l.append(int(input()))

    # pdb.set_trace()  
    l.sort()
    pairs = 0
    i = 0
    while(i < n-1):
        if l[i] + D >= l[i+1]:
            pairs += 1
            i += 2
        else:
            i += 1
    print(pairs)

main()
