class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        res = lambda nums : max(sum(1 for i in nums if i>0), sum(1 for i in nums if i<0))
        return res(nums)