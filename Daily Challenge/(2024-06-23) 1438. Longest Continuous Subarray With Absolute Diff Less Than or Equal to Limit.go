// Define a pair type
type pair struct {
    val, index int
}

// Define maxHeap and minHeap types
type maxHeap []pair
type minHeap []pair

// Implement heap.Interface for maxHeap
func (h maxHeap) Len() int            { return len(h) }
func (h maxHeap) Less(i, j int) bool  { return h[i].val > h[j].val }
func (h maxHeap) Swap(i, j int)       { h[i], h[j] = h[j], h[i] }
func (h *maxHeap) Push(x interface{}) { *h = append(*h, x.(pair)) }
func (h *maxHeap) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[0 : n-1]
    return x
}

// Implement heap.Interface for minHeap
func (h minHeap) Len() int            { return len(h) }
func (h minHeap) Less(i, j int) bool  { return h[i].val < h[j].val }
func (h minHeap) Swap(i, j int)       { h[i], h[j] = h[j], h[i] }
func (h *minHeap) Push(x interface{}) { *h = append(*h, x.(pair)) }
func (h *minHeap) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[0 : n-1]
    return x
}

func longestSubarray(nums []int, limit int) int {
    maxHeap := &maxHeap{}
    minHeap := &minHeap{}
    heap.Init(maxHeap)
    heap.Init(minHeap)

    left := 0
    maxLength := 0

    for right := 0; right < len(nums); right++ {
        heap.Push(maxHeap, pair{nums[right], right})
        heap.Push(minHeap, pair{nums[right], right})

        for (*maxHeap)[0].val-(*minHeap)[0].val > limit {
            left = min((*maxHeap)[0].index, (*minHeap)[0].index) + 1

            for (*maxHeap)[0].index < left {
                heap.Pop(maxHeap)
            }
            for (*minHeap)[0].index < left {
                heap.Pop(minHeap)
            }
        }

        maxLength = max(maxLength, right-left+1)
    }

    return maxLength
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}