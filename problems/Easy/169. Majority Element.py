class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 0
        ans = 0
        for i in nums:
            if count == 0:
                ans = i
                count = count + 1
            elif ans != i:
                count = count - 1
            else:
                count = count + 1
        return ans