func minPatches(nums []int, n int) int {
    len := len(nums)
    sm := 0
    res := 0
    i := 0
    for i < len && sm < n {
        if sm < nums[i] {
            if sm + 1 < nums[i] {
                res++
                sm += sm + 1
            } else {
                sm += nums[i]
                i++
            }
        } else {
            sm += nums[i]
            i++
        }
    }
    for sm < n {
        res++
        sm += sm + 1
    }
    // fmt.Println(sm, i)
    return res
}