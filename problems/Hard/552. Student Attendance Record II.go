const mod = 1000000007

func checkRecord(n int) int {
    dp := make([][][]int, n+1)
    for i := range dp {
        dp[i] = make([][]int, 2)
        for j := range dp[i] {
            dp[i][j] = make([]int, 3)
            for k := range dp[i][j] {
                dp[i][j][k] = -1
            }
        }
    }
    return find_eligibility(n, 0, 0, dp)
}

func find_eligibility(n int, absence int, late int, dp [][][]int) int {
    if absence == 2 || late == 3 {
        return 0
    }

    if n == 0 {
        return 1
    }

    if dp[n][absence][late] != -1 {
        return dp[n][absence][late] % mod
    }

    count := find_eligibility(n-1, absence, 0, dp) % mod
    count += find_eligibility(n-1, absence+1, 0, dp) % mod
    count += find_eligibility(n-1, absence, late+1, dp) % mod

    dp[n][absence][late] = count % mod
    return count % mod
}