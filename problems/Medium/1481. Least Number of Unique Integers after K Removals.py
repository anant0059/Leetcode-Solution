class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        dic = {}
        for i in arr:
            if i not in dic:
                dic[i] = 1
            else:
                dic[i] = dic[i] + 1
        l = []
        for i in dic:
            l.append(dic[i])
        l.sort()
        print(l)
        res = len(l)
        for i in l:
            if k - i >= 0:
                k = k - i
                res = res - 1
            else:
                break
        return res