class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n == 0:
            return 0
        neg = 0
        if n < 0:
            neg = 1
        n = abs(n)
        x = 1
        while n > 1:
            if n%2:
                return 0
            x = x + 1
            n = n/2
        if neg and x%2:
            return 0
        return 1