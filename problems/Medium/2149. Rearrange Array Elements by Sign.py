class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0]*n
        positive = -1
        negative = -1
        i = 0
        while positive < 0 or negative < 0:
            if nums[i] > 0 and positive < 0:
                positive = i
            if nums[i] < 0 and negative < 0:
                negative = i
            i = i + 1
        flag = 0
        i = 0
        print(positive, negative)
        while positive < n or negative < n:
            if flag == 0:
                res[i] = nums[positive]
                positive = positive + 1
                while positive < n and nums[positive]<0:
                    positive = positive + 1
                flag = 1
            else:
                res[i] = nums[negative]
                negative = negative + 1
                while negative < n and nums[negative]>0:
                    negative = negative + 1
                flag = 0
            i = i + 1
        return res