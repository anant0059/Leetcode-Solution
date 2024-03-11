class Solution:
    def customSortString(self, order: str, s: str) -> str:
        res = ""
        dic = {}
        for i in s:
            if i in dic:
                dic[i] = dic[i] + 1
            else:
                dic[i] = 1
        for i in order:
            if i in s:
                res = res + (i*dic[i])
        for i in s:
            if i not in res:
                res = res + (i*dic[i])
        return res