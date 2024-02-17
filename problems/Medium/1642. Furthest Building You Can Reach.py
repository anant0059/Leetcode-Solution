class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        n = len(heights)
        minheap = []
        for i in range(1, n):
            diff = heights[i] - heights[i-1]
            if diff > 0:
                bricks -= diff
                heapq.heappush(minheap, -diff)

                if bricks < 0:
                    if ladders == 0:
                        return i - 1
                    else:
                        bricks += -heapq.heappop(minheap)
                        ladders -= 1
        return n - 1