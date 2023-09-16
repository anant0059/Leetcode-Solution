class Solution:
    def minimumEffortPath(self, h: List[List[int]]) -> int:
        
        n = len(h)
        m = len(h[0])
        
        def calc(diff):
            
            q = [(0, 0)]
            seen = {(0, 0): 1}
            
            for x, y in q:
                hei = h[x][y]
                for i, j in [(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)]:
                    if 0 <= i < n and 0 <= j < m:
                        if abs(hei - h[i][j]) <= diff and (i, j) not in seen:
                            seen[(i, j)] = 1
                            q.append((i, j))
                            
            return (n - 1, m - 1) in seen
        
            
        l = 0
        r = 1_000_000
        
        while l < r:
            
            mid = (l + r) // 2
            if calc(mid):
                r = mid
            else:
                l = mid + 1
        
        return l