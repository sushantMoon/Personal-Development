class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last_visited = [-1] * 256
        start_pos = -1
        end_pos = -1
        max_length = 0
        for pos in range(len(s)):
            if last_visited[ord(s[pos])] != -1:
                if last_visited[ord(s[pos])] >= start_pos:
                    start_pos = last_visited[ord(s[pos])] + 1
                    last_visited[ord(s[pos])] = pos
            if start_pos == -1:
                start_pos = pos
            end_pos = pos
            max_length = max(max_length, end_pos-start_pos+1)
            last_visited[ord(s[pos])] = pos
        return max_length
