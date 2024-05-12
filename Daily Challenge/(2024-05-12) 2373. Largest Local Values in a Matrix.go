func largestLocal(grid [][]int) [][]int {
    n := len(grid)
    var res [][]int
    for i:=0 ; i<n-2 ; i++ {
        var tmp []int
        for j:=0 ; j<n-2 ; j++ {
            mx := grid[i][j]
            for l:=0 ; l<3 ; l++ {
                for m:=0 ; m<3 ; m++ {
                    // mx = int(math.Max(float64(mx), float64(grid[i+l][m+j])))
                    mx = max(mx, grid[i+l][j+m])
               }
            }
            tmp = append(tmp, mx)
        }
        res = append(res, tmp)
    }
    return res
}