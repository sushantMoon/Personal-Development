class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        H = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            H[i][n-1] = 1
        for i in range(n):
            H[m-1][i] = 1
        for i in range(m-2, -1, -1):
            for j in range(n-2, -1, -1):
                H[i][j] = H[i+1][j] + H[i][j+1]
        return H[0][0]
