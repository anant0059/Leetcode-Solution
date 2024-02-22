class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        mp = [0]*(n+1)
        for i in trust:
            mp[i[1]] = mp[i[1]] + 1
            mp[i[0]] = mp[i[0]] - 1
        # print(mp)
        for i in range(1, n+1):
            if mp[i] == n-1:
                return i
        return -1