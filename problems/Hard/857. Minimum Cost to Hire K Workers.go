/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// PASSED APPROACH - 3

import (
    "container/heap"
    "fmt"
    "math"
)
// An Item is something we manage in a priority queue.
type Item struct {
	val int // The value of the item; arbitrary.
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
	*pq = append(*pq, x.(Item))
}

func (pq *PriorityQueue) Pop() any {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

type worker struct {
	quality int
    wage int
    ratio float64
}

func mincostToHireWorkers(quality []int, wage []int, k int) float64 {
    n := len(quality)
    // fmt.Println(n)
    res := math.MaxFloat64

    workers := make([]worker, n)
    for i:=0 ; i<n ; i++ {
        workers[i] = worker{quality[i], wage[i], float64(wage[i])/float64(quality[i])}
    }

    sort.Slice(workers, func(i, j int) bool {
		return workers[i].ratio < workers[j].ratio
	})

    // fmt.Println(workers)

    pq := &PriorityQueue{}
    heap.Init(pq)

    qualitySum := 0
    for i:=0 ; i<n ; i++ {
        heap.Push(pq, Item{workers[i].quality})
        qualitySum += workers[i].quality
        if pq.Len() > k {
            qualitySum -= heap.Pop(pq).(Item).val
        }
        cost := float64(workers[i].wage*qualitySum) / float64(workers[i].quality)
		if pq.Len() == k && cost < res {
			res = cost
		}
    }
    return res
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// TLE APPROACH - 2

import (
    "container/heap"
    "fmt"
    "math"
)
// An Item is something we manage in a priority queue.
type Item struct {
	val float64 // The value of the item; arbitrary.
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
	*pq = append(*pq, x.(Item))
}

func (pq *PriorityQueue) Pop() any {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

type worker struct {
	quality int
    wage int
    ratio float64
}

func mincostToHireWorkers(quality []int, wage []int, k int) float64 {
    n := len(quality)
    // fmt.Println(n)
    res := math.MaxFloat64

    workers := make([]worker, n)
    for i:=0 ; i<n ; i++ {
        workers[i] = worker{quality[i], wage[i], float64(wage[i])/float64(quality[i])}
    }

    sort.Slice(workers, func(i, j int) bool {
		return workers[i].ratio < workers[j].ratio
	})

    // fmt.Println(workers)


    for i:=k-1 ; i<n ; i++ {
        pq := &PriorityQueue{}
        heap.Init(pq)

        tmp := float64(0)
        ratio := workers[i].ratio
        // fmt.Println(ratio)
        for j:=0 ; j<=i ; j++ {
            val := ratio * float64(workers[j].quality)
            if pq.Len() < k {
                if ratio >= workers[j].ratio {
                    heap.Push(pq, Item{val})
                    tmp = tmp + val
                }
            } else {
                if (*pq)[0].val > val && ratio >= workers[j].ratio {
                    pop_pq := heap.Pop(pq)
                    // fmt.Println("pop_pq. ", pop_pq)
                    tmp = tmp - pop_pq.(Item).val
                    heap.Push(pq, Item{val})
                    tmp = tmp + val
                }
            }
        }
        if pq.Len() == k {
            res = math.Min(res, tmp)
        }
        // fmt.Println(pq)
    }
    return res
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// TLE APPROACH - 1


import (
    "container/heap"
    "fmt"
    "math"
)
// An Item is something we manage in a priority queue.
type Item struct {
	val float64 // The value of the item; arbitrary.
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
	*pq = append(*pq, x.(Item))
}

func (pq *PriorityQueue) Pop() any {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}


func mincostToHireWorkers(quality []int, wage []int, k int) float64 {
    n := len(quality)
    // fmt.Println(n)
    res := math.MaxFloat64

    for i:=0 ; i<n ; i++ {
        pq := &PriorityQueue{}
        heap.Init(pq)

        tmp := float64(0)
        ratio := float64(wage[i])/float64(quality[i])
        // fmt.Println(ratio)
        for j:=0 ; j<n ; j++ {
            val := math.Max(ratio * float64(quality[j]), float64(wage[j]))
            if pq.Len() < k {
                if ratio >= float64(wage[j])/float64(quality[j]) {
                    heap.Push(pq, Item{val})
                    tmp = tmp + val
                }
            } else {
                if (*pq)[0].val > val && ratio >= float64(wage[j])/float64(quality[j]) {
                    pop_pq := heap.Pop(pq)
                    // fmt.Println("pop_pq. ", pop_pq)
                    tmp = tmp - pop_pq.(Item).val
                    heap.Push(pq, Item{val})
                    tmp = tmp + val
                }
            }
        }
        if pq.Len() == k {
            res = math.Min(res, tmp)
        }
        // fmt.Println(pq)
    }
    return res
}