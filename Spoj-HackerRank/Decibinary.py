"""

Author : SUshant

Problem Link : https://www.hackerrank.com/challenges/decibinary-numbers/problem

"""

class Decibinary:
    def __init__(self):
        pass

    def convert_to_db(self, decibin):
        original_value = decibin
        two_power_i = 1
        return_value = 0
        while(decibin > 0):
            return_value += ((decibin%10) * two_power_i)
            decibin = int(decibin / 10)
            two_power_i = two_power_i * 2
        return (original_value, int(return_value))

d = Decibinary()

for j in range(0, 11):
    decimal_array = []
    for i in range(0, 10):
        decimal_array.append(d.convert_to_db(j*10 + i))
    print(decimal_array)


