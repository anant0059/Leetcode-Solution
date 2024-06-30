type UnionFind struct {
	parent     []int
	size       []int
	components int
}

// NewUnionFind initializes a Union-Find structure with `n` elements
func NewUnionFind(n int) *UnionFind {
	uf := &UnionFind{
		parent:     make([]int, n+1),
		size:       make([]int, n+1),
		components: n,
	}
	for i := 0; i <= n; i++ {
		uf.parent[i] = i
		uf.size[i] = 1
	}
	return uf
}

// find finds the root of x with path compression
func (uf *UnionFind) find(x int) int {
	if uf.parent[x] != x {
		uf.parent[x] = uf.find(uf.parent[x])
	}
	return uf.parent[x]
}

// unite merges the sets containing x and y
func (uf *UnionFind) unite(x, y int) bool {
	rootX := uf.find(x)
	rootY := uf.find(y)
	if rootX == rootY {
		return false
	}
	if uf.size[rootX] < uf.size[rootY] {
		rootX, rootY = rootY, rootX
	}
	uf.parent[rootY] = rootX
	uf.size[rootX] += uf.size[rootY]
	uf.components--
	return true
}

// isConnected checks if all nodes are in one component
func (uf *UnionFind) isConnected() bool {
	return uf.components == 1
}

// maxNumEdgesToRemove calculates the maximum number of edges that can be removed
func maxNumEdgesToRemove(n int, edges [][]int) int {
	alice := NewUnionFind(n)
	bob := NewUnionFind(n)
	edgesRequired := 0

	// Process type 3 edges first
	for _, edge := range edges {
		if edge[0] == 3 {
			aliceUnion := alice.unite(edge[1], edge[2])
			bobUnion := bob.unite(edge[1], edge[2])
			if aliceUnion || bobUnion {
				edgesRequired++
			}
		}
	}

	// Process type 1 edges for Alice
	for _, edge := range edges {
		if edge[0] == 1 {
			if alice.unite(edge[1], edge[2]) {
				edgesRequired++
			}
		}
	}

	// Process type 2 edges for Bob
	for _, edge := range edges {
		if edge[0] == 2 {
			if bob.unite(edge[1], edge[2]) {
				edgesRequired++
			}
		}
	}

	// Check if both are fully connected
	if alice.isConnected() && bob.isConnected() {
		return len(edges) - edgesRequired
	}

	return -1
}