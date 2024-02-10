class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        res = 0
        for i in range(n):
            left = i - 1
            right = i + 1
            res = res + 1
            while left > -1 and right < n and s[left] == s[right]:
                res = res + 1
                left = left -1
                right = right + 1
            left = i
            right = i + 1
            while left > -1 and right < n and s[left] == s[right]:
                res = res + 1
                left = left -1
                right = right + 1
        return res