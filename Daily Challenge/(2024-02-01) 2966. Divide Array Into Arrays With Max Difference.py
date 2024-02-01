class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        res = []
        n = len(nums)
        nums.sort()
        print(nums)
        i = 0
        while i<n-2:
            if(nums[i+2]-nums[i]<=k):
                res.append([nums[i],nums[i+1],nums[i+2]])
                i = i+3
                print(i)
            else:
                return []
        return res