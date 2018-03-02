# https://leetcode.com/problems/valid-palindrome/
class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        from string import maketrans
        from string import punctuation
        s = s.encode('utf-8').translate(maketrans("",""),punctuation+' ').lower()
        
        for i in range(0,int(len(s)/2)):
            if s[i] != s[len(s) - i -1] :
                return False
        return True
        