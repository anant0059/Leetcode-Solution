class Solution:
    def countBits(self, n: int) -> List[int]:
        res = [0]*(n+1)
        curr = 2
        past = 1
        while(past <= n):
            # print("curr", past, curr)
            for i in range(past, min(curr, n+1)):
                res[i] = res[i-past] + 1
            past = curr
            curr *= 2
        return res