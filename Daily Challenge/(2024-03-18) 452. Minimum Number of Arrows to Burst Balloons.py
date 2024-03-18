class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort()
        lp = points[0][1]
        ans = 1
        for i in points:
            if i[0] > lp:
                ans = ans + 1
                lp = i[1]
            lp = min(i[1], lp)
        return ans