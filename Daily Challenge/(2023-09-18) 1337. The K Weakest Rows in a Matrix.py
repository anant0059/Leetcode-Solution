class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        n = len(mat)
        m = len(mat[0])
        heap = [0]*n
        for i in range(n):
            l = 0
            r = m-1
            mid = (l+r)//2
            while l <= r:
                mid = (l+r)//2
                if mat[i][mid] == 1:
                    l = mid + 1
                else:
                    r = mid - 1
            heap[i] = (l, i)
        heapify(heap)
        res = []
        while k>0:
            sols, idx = heappop(heap)
            res.append(idx)
            k -= 1
        return res