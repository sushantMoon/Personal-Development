"""
Sushant Moon
Date 14/7/2018
Activity Selection Problem
Reference : 
https://www.geeksforgeeks.org/greedy-algorithms-set-1-activity-selection-problem/
"""

def activity_selection(activity):
    activity = sorted(activity, key=lambda item:item[1])
    results = []
    results.append(activity[0])
    for index, item in enumerate(activity):
        if index == 0:
            pass
        else:
            if results[-1][1] <= activity[index][0]:
                results.append(activity[index])
    for item in results:
        print("Starts at {start} ----- Ends at => {end}".format(start=item[0], end=item[1])) 


s = [[1,2] , [3,4] , [0,6] , [5,7] , [8,9] , [5,9]]
activity_selection(s)


