class Solution:
    def numSquares(self, n: int) -> int:
        dp = [10000]*(n+1)
        dp[0] = 0
        for i in range(1,n+1):
            tmp = 1
            while tmp*tmp <= i:
                dp[i] = min(dp[i], dp[i-tmp*tmp]+1)
                tmp = tmp+1
        return dp[n]