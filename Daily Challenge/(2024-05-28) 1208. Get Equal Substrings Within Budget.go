func equalSubstring(s string, t string, maxCost int) int {
    n := len(s)
    currCost := 0
    j := 0
    res := 0
    for i := 0 ; i < n ; i++ {
        for j < n && currCost + int(math.Abs(float64(t[j])- float64(s[j]))) <= maxCost {
            currCost = currCost + int(math.Abs(float64(t[j])- float64(s[j])))
            fmt.Println(currCost, j)
            j++
        }
        res = max(res, j-i)
        if int(math.Abs(float64(t[i])- float64(s[i]))) <= maxCost {
            currCost = currCost - int(math.Abs(float64(t[i])- float64(s[i])))
        }
        if i == j {
            j++
            if s[i] == t[i] {
                res = max(res, 1)
            }
        }
    }
    return res
}