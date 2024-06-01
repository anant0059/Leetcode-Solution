func scoreOfString(s string) int {
    n := len(s)
    res := 0
    for i:=0 ; i<n-1 ; i++ {
        res += int(math.Abs(float64(s[i]) - float64(s[i+1])))
    }
    return res
}