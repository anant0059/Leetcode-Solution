class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        if len(pairs) == 0:
            return 0
        
        dp = []
        for i in range(len(pairs)):
            dp.append(1)

        pairs.sort(key=lambda x:x[0])

        for i in range(len(pairs)):
            # print(i)
            for j in range(i):
                print(j)
                if pairs[i][0] > pairs[j][1]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return dp[len(pairs) -1]