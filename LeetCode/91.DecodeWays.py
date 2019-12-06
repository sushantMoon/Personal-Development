class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        count = [0] * (n+1)
        count[0] = 1
        count[1] = 1
        if s[0] == '0':
            return 0
        for i in range(2, n+1):
            if int(s[i-1]) > 0:
                count[i] = count[i-1]
            if (int(s[i-2]) == 1) or (int(s[i-2]) == 2 and int(s[i-1]) < 7):
                count[i] += count[i-2]
        return count[n]
