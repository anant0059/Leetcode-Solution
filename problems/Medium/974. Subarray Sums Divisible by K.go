func subarraysDivByK(nums []int, k int) int {
    res := 0
    freq := make(map[int]int)
    sm := 0
    freq[0] = 1
    for _, num := range nums {
        sm += num % k
        sm %= k
        // fmt.Println(sm)
        if sm < 0 {
            // fmt.Println("here", sm)
            sm = k + sm
            // fmt.Println("here1", sm)
        }
        if freq[sm] > 0 {
            res += freq[sm]
        }
        freq[sm]++
    }
    return res
}