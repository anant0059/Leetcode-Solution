class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        res = -1
        sm = nums[0] + nums[1]
        for i in range(2, n):
            if sm > nums[i]:
                res = sm + nums[i]
            sm = sm + nums[i]
        return res
