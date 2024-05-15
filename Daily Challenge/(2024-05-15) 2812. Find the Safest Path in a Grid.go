// Direction vectors for moving to neighboring cells: right, left, down, up
var dir = [][]int{
	{0, 1},
	{0, -1},
	{1, 0},
	{-1, 0},
}

// Pair represents a coordinate in the grid
type Pair struct {
	x, y int
}

// Cell represents a cell with its safeness factor and coordinates
type Cell struct {
	safeness, x, y int
}

// PriorityQueue implements heap.Interface for a priority queue of Cells
type PriorityQueue []*Cell

func (pq PriorityQueue) Len() int { return len(pq) }
func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].safeness > pq[j].safeness // Max-heap based on safeness factor
}
func (pq PriorityQueue) Swap(i, j int) { pq[i], pq[j] = pq[j], pq[i] }

func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.(*Cell))
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

// isValidCell checks if a given cell lies within the grid
func isValidCell(grid [][]int, i, j int) bool {
	n := len(grid)
	return i >= 0 && j >= 0 && i < n && j < n
}

// maximumSafenessFactor calculates the maximum safeness factor
func maximumSafenessFactor(grid [][]int) int {
	n := len(grid)
	multiSourceQueue := make([]Pair, 0)

	// Mark thieves as 0 and empty cells as -1, and push thieves to the queue
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 1 {
				multiSourceQueue = append(multiSourceQueue, Pair{i, j})
				grid[i][j] = 0
			} else {
				grid[i][j] = -1
			}
		}
	}

	// Calculate safeness factor for each cell using BFS
	for len(multiSourceQueue) > 0 {
		size := len(multiSourceQueue)
		for size > 0 {
			curr := multiSourceQueue[0]
			multiSourceQueue = multiSourceQueue[1:]
			size--
			for _, d := range dir {
				di := curr.x + d[0]
				dj := curr.y + d[1]
				val := grid[curr.x][curr.y]
				if isValidCell(grid, di, dj) && grid[di][dj] == -1 {
					grid[di][dj] = val + 1
					multiSourceQueue = append(multiSourceQueue, Pair{di, dj})
				}
			}
		}
	}

	// Priority queue to prioritize cells with higher safeness factor
	pq := &PriorityQueue{}
	heap.Init(pq)
	// Push starting cell to the priority queue
	heap.Push(pq, &Cell{grid[0][0], 0, 0})
	grid[0][0] = -1 // Mark the source cell as visited

	// BFS to find the path with maximum safeness factor
	for pq.Len() > 0 {
		curr := heap.Pop(pq).(*Cell)
		// If reached the destination, return safeness factor
		if curr.x == n-1 && curr.y == n-1 {
			return curr.safeness
		}
		for _, d := range dir {
			di := d[0] + curr.x
			dj := d[1] + curr.y
			if isValidCell(grid, di, dj) && grid[di][dj] != -1 {
				heap.Push(pq, &Cell{min(curr.safeness, grid[di][dj]), di, dj})
				grid[di][dj] = -1
			}
		}
	}

	return -1 // No valid path found
}

// min returns the smaller of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}