func combinationSum3(k int, n int) [][]int {
    res := make([][]int, 0)
    current := make([]int, 0)
    dfs(&res, current, k, n, 1)
    return res
}

func dfs(res *[][]int, curr []int, k int, n int, start int) {
    if n < 0 || k < 0 {
        return
    }
    if k == 0 {
        if n == 0 {
            // Create a copy of the current combination to avoid modifying it later
            copyCurr := make([]int, len(curr))
            copy(copyCurr, curr)
            *res = append(*res, copyCurr)
        }
        return
    }

    for i := start; i <= 9; i++ {
        curr = append(curr, i)
        fmt.Println(curr)
        dfs(res, curr, k-1, n-i, i+1)
        // Backtrack: remove the last element to try a different combination
        curr = curr[:len(curr)-1]
    }
}
