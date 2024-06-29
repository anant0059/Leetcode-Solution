func getAncestors(n int, edges [][]int) [][]int {
    // Initialize the reversed adjacency list
    revAdj := make([][]int, n)
    for _, edge := range edges {
        revAdj[edge[1]] = append(revAdj[edge[1]], edge[0])
    }

    // Function to perform BFS and collect ancestors
    var bfs func(start int) []int
    bfs = func(start int) []int {
        visited := make([]bool, n)
        queue := []int{start}
        ancestors := make([]int, 0)

        for len(queue) > 0 {
            node := queue[0]
            queue = queue[1:]

            for _, neighbor := range revAdj[node] {
                if !visited[neighbor] {
                    visited[neighbor] = true
                    ancestors = append(ancestors, neighbor)
                    queue = append(queue, neighbor)
                }
            }
        }

        sort.Ints(ancestors) // Ensure ancestors are sorted
        return ancestors
    }

    // Initialize the result array to store ancestors for each node
    result := make([][]int, n)
    for i := 0; i < n; i++ {
        result[i] = bfs(i)
    }

    return result
}