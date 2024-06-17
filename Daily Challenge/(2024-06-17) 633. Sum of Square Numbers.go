func judgeSquareSum(c int) bool {
    n := int(math.Sqrt(float64(c))) + 1
    // fmt.Println(n)
    for i := 0; i < n; i++ {
        tmp := math.Pow(float64(i), 2)
        tmp1 := float64(c) - tmp
        tmp2 := math.Sqrt(tmp1)
        if tmp2 - float64(int(tmp2)) == 0 {
            return true
        }
    }
    return false
}