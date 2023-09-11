class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        dic = {}
        res = []
        for i in range(len(groupSizes)):
            if groupSizes[i] in dic:
                dic[groupSizes[i]].append(i)
            else:
                dic[groupSizes[i]] = [i]
            if len(dic[groupSizes[i]]) == groupSizes[i]:
                res.append(dic[groupSizes[i]])
                dic[groupSizes[i]] = []
        return res