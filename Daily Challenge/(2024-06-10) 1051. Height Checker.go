func heightChecker(heights []int) int {
    // fmt.Println(heights)
    expected := make([]int, len(heights))
    copy(expected, heights)
    res := 0
    slices.Sort(expected)
    // fmt.Println(expected)
    for i, height := range heights {
        // fmt.Println(height, expected[i])
        if height != expected[i] {
            res++
        }
    }
    return res
}