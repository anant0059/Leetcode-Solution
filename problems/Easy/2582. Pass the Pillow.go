func passThePillow(n int, time int) int {
    x := time / (n-1)
    y := time % (n-1)
    fmt.Println(x, y)
    if x%2 == 0 {
        return y + 1
    }
    return n - y
}