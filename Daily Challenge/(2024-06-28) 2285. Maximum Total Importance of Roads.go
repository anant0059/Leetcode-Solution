func maximumImportance(n int, roads [][]int) int64 {
    dp := make([]int, n)
    for _, road := range roads {
        dp[road[0]]++
        dp[road[1]]++
    }
    slices.Sort(dp)
    res := 0
    for i, count := range dp {
        res = res + (i+1)*count
    }
    fmt.Println(dp)
    return int64(res)
}