class Solution:
    def firstUniqChar(self, s: str) -> int:
        n = len(s)
        arr = {}
        for i in range(n):
            if s[i] in arr:
                arr[s[i]] = arr[s[i]]+1
            else:
                arr[s[i]] = 1
        print(arr)
        for i in range(n):
            if arr[s[i]] == 1:
                return i
        return -1