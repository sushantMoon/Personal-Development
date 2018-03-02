# https://leetcode.com/problems/single-number/
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        number = 0
        for i in nums :
            number ^= i
        
        return number
      