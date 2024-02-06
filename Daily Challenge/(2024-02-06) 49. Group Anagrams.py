class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dic = {}
        res = []
        for i in strs:
            tmp = sorted(i)
            tmp = ''.join(tmp)
            if tmp in dic:
                dic[tmp].append(i)
            else:
                dic[tmp]=[i]
        for i in dic:
            res.append(dic[i])
        return res