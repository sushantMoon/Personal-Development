class Solution:
    def myAtoi(self, str: str) -> int:
        num = 0
        sign = 0
        flag = False
        for i in range(len(str)):
            if str[i] == ' ':
                if flag == True:
                    break
                pass
            elif '-' == str[i]:
                if flag == True:
                    break
                else:
                    if sign == 1:
                        break
                    sign = -1
                    flag = True
            elif '+' == str[i]:
                if flag == True:
                    break
                else:
                    if sign == -1:
                        break
                    sign = 1
                    flag = True
            elif ord('0') <= ord(str[i]) and ord('9') >= ord(str[i]):
                num = 10*num + int(str[i])
                flag = True
            elif ord('0') > ord(str[i].lower()) or ord('9') < ord(str[i].lower()):
                break
        if sign == 0:
            sign = 1
        num = sign*num
        if num > (2**31)-1:
            return (2**31)-1
        elif num < -1*2**31:
            return -1*2**31
        else:
            return num
