class Solution:
    def firstPalindrome(self, words: List[str]) -> str:
        for i in words:
            l = 0
            r = len(i) - 1
            while l < r and i[l] == i[r]:
                l = l+1
                r = r-1
            if r<=l:
                return i
        return ""

