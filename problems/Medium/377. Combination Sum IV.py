class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = [0] * (target+1) 
        for i in range(1, target+1):            # offset from 1 to skip base case (first element)
            for n in nums:
                if( n == i):                    # If number is in the list, you can directly count it as one combination
                        dp[i] += 1
                if n < i:                       
                        dp[i] += dp[i-n]        # include all the combinations of target i-n.
        return dp[-1]