class Solution:
    def frequencySort(self, s: str) -> str:
        dic = {}
        for i in s:
            if i in dic:
                dic[i] = dic[i] + 1
            else:
                dic[i] = 1
        arr = []
        for i in dic:
            arr.append([dic[i],i])
        arr.sort()
        res = ""
        # print(arr)
        for i in arr:
            for j in range(i[0]):
                res = i[1] + res
        return res