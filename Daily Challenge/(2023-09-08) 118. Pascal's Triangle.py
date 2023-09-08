class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = [[1]]
        for i in range(1, numRows):
            temp = [1]
            for j in range(i-1):
                # print(i,j)
                temp.append(res[i-1][j]+res[i-1][j+1])
            temp.append(1)
            res.append(temp)
        return res