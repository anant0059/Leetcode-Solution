func matrixScore(grid [][]int) int {
    n := len(grid)
    m := len(grid[0])
    res := math.Pow(2, float64(m-1)) * float64(n)
    for i:=1 ; i<m ; i++ {
        one := 0
        for j:=0 ; j<n ; j++ {
            if grid[j][0] == grid[j][i]{
                one++;
            }
        }
        one = max(one, n-one)
        res = res + math.Pow(2, float64(m-i-1)) * float64(one)
    }
    return int(res)
}