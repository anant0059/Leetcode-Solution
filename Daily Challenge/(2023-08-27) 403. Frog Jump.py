class Solution:
    def canCross(self, stones: List[int]) -> bool:
        n = len(stones)
        dp = [set() for _ in range(n)]
        mp = {}
        for i in range(n):
            mp[stones[i]] = i
            # print(mp[stones[i]])
        if 1 in stones:
            dp[mp[1]].add(1)
        for i in range(1, n):
            for j in dp[i]:
                # print(j)
                # print(stones[i])
                # if 2 in mp:
                #     print(mp[2])
                # print(mp[j+stones[i]])
                if(j+stones[i] in mp and mp[j+stones[i]] and mp[j+stones[i]] != i):
                    dp[mp[j+stones[i]]].add(j)
                if(j+stones[i]+1 in mp and mp[j+stones[i]+1] and mp[j+stones[i]+1] != i):
                    dp[mp[j+stones[i]+1]].add(j+1)
                if(j+stones[i]-1 in mp and mp[j+stones[i]-1] and mp[j+stones[i]-1] != i):
                    dp[mp[j+stones[i]-1]].add(j-1)
        # print(mp)
        # print(dp)
        if(len(dp[-1]) > 0):
            return True
        return False