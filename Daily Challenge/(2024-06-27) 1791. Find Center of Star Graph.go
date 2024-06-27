func findCenter(edges [][]int) int {
    // n := len(edges)
    mp := make(map[int]int)
    // fmt.Println(mp)
    // res := n
    for _, edge := range edges {
        if mp[edge[0]] > 0 {
            return edge[0]
        }
        if mp[edge[1]] > 0 {
            return edge[1]
        }
        mp[edge[0]] = 1
        mp[edge[1]] = 1
    }
    return edges[0][0]
}