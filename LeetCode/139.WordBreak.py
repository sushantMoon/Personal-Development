class Solution:
#     def wordBreak(self, s: str, wordDict: List[str]) -> bool:
#         return self.recF(0, 0, wordDict, s)
    
#     def recF(self, start, last, wordDict, s):
#         if start == len(s):
#             return True
#         elif last > len(s):
#             return False
#         elif s[start:last+1] in wordDict:
#             return (
#                 self.recF(last+1, last+1, wordDict, s)
#             ) or (
#                 self.recF(start, last+1, wordDict, s)
#             )
#         else:
#             return self.recF(start, last+1, wordDict, s)
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        # here row number of a matrix represents ending index (last == row)
        # column number represents starting index for matching (start == col)
        # to understand more clearly first think recursively.
        length = len(s)
        matrix = [ [False for _ in range(length)] for _ in range(length)]
        
        for row in range(length-1, -1, -1):
            for col in range(row, -1, -1):
                if col > row:
                    pass
                else:
                    if s[col:row+1] in wordDict:
                        if row == length-1:
                            matrix[row][col] = True
                        else:
                            matrix[row][col] = any(matrix[j][row+1] == True for j in range(row+1, length, 1)) or (matrix[row+1][col])
        for row in range(length):
            if matrix[row][0] == True:
                return True
        return False
        
            
