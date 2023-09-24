class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        tower = []
        for i in range(101):
            tower.append([0]*(i+1))
        # print(tower)
        tower[0][0] = poured
        for i in range(100):
            for j in range(i+1):
                if tower[i][j] >= 1: 
                    tower[i+1][j] += (tower[i][j] - 1)/2
                    tower[i+1][j+1] += (tower[i][j] - 1)/2
                    tower[i][j] = 1
                if i == query_row and j == query_glass:
                    return tower[i][j]
        return 0