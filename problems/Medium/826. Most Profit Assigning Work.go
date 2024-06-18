import (
	"container/heap"
	"fmt"
)

// Item is something we manage in a priority queue.
type Item struct {
	profit_val   int
	difficulty_val int
}

// A PriorityQueue implements heap.Interface and holds Items.
type PriorityQueue []Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	// We want Pop to give us the highest, not lowest, priority so we use greater than here.
	return pq[i].profit_val > pq[j].profit_val
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x any) {
	item := x.(Item)
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() any {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

func maxProfitAssignment(difficulty []int, profit []int, worker []int) int {
    n := len(difficulty)
    m := len(worker)
    res := 0

    pq := &PriorityQueue{}
	heap.Init(pq)
    for i := 0; i < n; i++ {
        heap.Push(pq, Item{profit_val: profit[i], difficulty_val: difficulty[i]})
    }
    fmt.Println(pq)
    slices.Sort(worker)
    for w := m-1; w >= 0; w-- {
        for pq.Len() > 0 && (*pq)[0].difficulty_val > worker[w] {
			heap.Pop(pq)
		}
		if pq.Len() > 0 {
			res += (*pq)[0].profit_val
            fmt.Println((*pq)[0].profit_val, (*pq)[0].difficulty_val, worker[w])
		}
    }
    return res
}