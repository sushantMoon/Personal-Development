# https://leetcode.com/problems/two-sum/

# Poor Time Complexity (Percentile : 25 %)
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(len(nums)):
            first = nums[i]
            for j in range(i+1,len(nums)):
                second = nums[j]
                if first + second == target:
                    return [i,j]

# Better Time Complexity (Percentile : 61 %)
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        complimentary = {}
        for i in range(len(nums)):
            comp = target - nums[i]
            if comp in complimentary:
                return [complimentary[comp],i]
            complimentary[nums[i]] = i
