// An Item is something we manage in a priority queue.
type Item struct {
	val float64 // The value of the item; arbitrary.
	i int    // The priority of the item in the queue.
	// The index is needed by update and is maintained by the heap.Interface methods.
	j int // The index of the item in the heap.
}

// A PriorityQueue implements heap.Interface and holds Items.
type PriorityQueue []Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	// We want Pop to give us the highest, not lowest, priority so we use greater than here.
	return pq[i].val < pq[j].val
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x any) {
	*pq = append(*pq, x.(Item))
}

func (pq *PriorityQueue) Pop() any {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}



func kthSmallestPrimeFraction(arr []int, k int) []int {
    pq := &PriorityQueue{}
    heap.Init(pq)

    n := len(arr)
    for i:=0 ; i<n ; i++ {
        item := Item{float64(arr[i])/float64(arr[n-1]), i, n-1}
        heap.Push(pq, item)
    }

    res := []int{}

    for k >= 0{
        curr := heap.Pop(pq)
        curr1 := curr.(Item)
        fmt.Println(curr)
        k--
        if k == 0 {
            res = append(res, arr[curr1.i])
            res = append(res, arr[curr1.j])
        }

        num := curr1.i
        den := curr1.j - 1
        if num < den {
            heap.Push(pq, Item{
                float64(arr[num])/float64(arr[den]),
                num,
                den})
        }
    }
    return res
}

