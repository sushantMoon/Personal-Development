class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        maxlen = 1
        start = 0
        table = [[0 for _ in range(n)] for _ in range(n)]
        for i in range(0, n):
            table[i][i] = 1
        for i in range(0, n-1):
            if s[i] == s[i+1]:
                maxlen = 2
                start = i
                table[i][i+1] = 1
        for l in range(3, n+1):
            for i in range(0, n-l+1):
                j = i+l-1
                if (table[i+1][j-1] == 1) and (s[i] == s[j]):
                    table[i][j] = 1
                    if l > maxlen:
                        maxlen = l
                        start = i
        return s[start: start+maxlen: 1]
