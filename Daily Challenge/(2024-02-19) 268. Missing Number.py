class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        xor = 0
        for i in range(1,n+1):
            xor = xor ^ i
            xor = xor ^ nums[i-1]
        return xor