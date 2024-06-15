import (
	"container/heap"
	"fmt"
	"sort"
)

// Item is something we manage in a priority queue.
type Item struct {
	val float64 // The value of the item; arbitrary.
	i   int     // The priority of the item in the queue.
	// The index is needed by update and is maintained by the heap.Interface methods.
	j int // The index of the item in the heap.
}

// A PriorityQueue implements heap.Interface and holds Items.
type PriorityQueue []Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	// We want Pop to give us the highest, not lowest, priority so we use greater than here.
	return pq[i].val > pq[j].val
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

func findMaximizedCapital(k int, w int, profits []int, capital []int) int {
	n := len(profits)
	projects := make([][2]int, n)
	for i := 0; i < n; i++ {
		projects[i] = [2]int{capital[i], profits[i]}
	}
	// Sort projects by their capital requirements
	sort.Slice(projects, func(i, j int) bool {
		return projects[i][0] < projects[j][0]
	})

	pq := &PriorityQueue{}
	heap.Init(pq)
	i := 0

	for k > 0 {
		// Add all projects that can be funded with the current capital to the priority queue
		for i < n && projects[i][0] <= w {
			heap.Push(pq, Item{val: float64(projects[i][1]), i: projects[i][1]})
			i++
		}
		if pq.Len() == 0 {
			break
		}
		// Select the project with the maximum profit
		w += int(heap.Pop(pq).(Item).val)
		k--
	}
	return w
}
