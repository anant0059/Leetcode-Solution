func maximumHappinessSum(happiness []int, k int) int64 {
    // len := len(happiness)
    // fmt.Println(len)
    sort.Slice(happiness, func(i, j int) bool {
        return happiness[i] > happiness[j]
    })
    var res int
    for i := 0; i<k; i++ {
        if happiness[i] - i >= 0 {
            res = res + happiness[i] - i
        }
    }
    // fmt.Println(happiness)
    return int64(res)
}