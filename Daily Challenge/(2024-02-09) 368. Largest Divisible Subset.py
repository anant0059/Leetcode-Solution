class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        n = len(nums)
        dp = [1] * n
        max_size, max_index = 1, 0

        for i in range(1, n):
            for j in range(i):
                if nums[i] % nums[j] == 0:
                    dp[i] = max(dp[i], dp[j] + 1)
                    if dp[i] > max_size:
                        max_size = dp[i]
                        max_index = i

        print(dp)
        print(max_index)
        print(max_size)
        result = []
        num = nums[max_index]
        for i in range(max_index, -1, -1):
            if num % nums[i] == 0 and dp[i] == max_size:
                result.append(nums[i])
                num = nums[i]
                max_size -= 1

        return result

# class Solution:
#     def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
#         if len(nums)==1:
#             return nums
#         res = []
#         nums.sort()
#         # print(nums[-1])
#         for i in range(2, 100):
#             if i in nums:
#                 tmp = [i]
#                 x = i*i
#                 while x <= nums[-1]:
#                     # print(x)
#                     if x in nums:
#                         tmp.append(x)
#                     x = x*i
#                     # print(x)
#                 biggest = tmp[-1]
#                 for j in nums:
#                     if (biggest%j == 0 or j%biggest == 0) and j not in tmp:
#                         tmp.append(j)
#                 print(tmp)
#                 if len(tmp) > len(res):
#                     res = tmp
#         # if len(res) == 0 and 1 in nums and len(nums) > 1:
#         #     return nums[0:2]
#         # if len(res) and 1 in nums:
#         #     res.append(1)
#         if len(res)==0:
#             return [nums[0]]
#         return res
#         # res = []
#         # mx = 0
#         # for i in nums:
#         #     tmp = []
#         #     for j in nums:
#         #         if i != j and (i%j == 0 or j%i==0):
#         #             tmp.append(j)
#         #     tmp.append(i)
#         #     if len(tmp) > mx:
#         #         mx = len(tmp)
#         #         res = tmp
#         # return res