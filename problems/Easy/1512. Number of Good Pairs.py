class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        dic = {}
        res = 0
        for i in nums:
            if i in dic:
                res += dic[i]
                dic[i] += 1
            else:
                dic[i] = 1
        return res