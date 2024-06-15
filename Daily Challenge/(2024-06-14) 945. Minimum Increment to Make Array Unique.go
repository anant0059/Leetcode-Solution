func minIncrementForUnique(nums []int) int {
    slices.Sort(nums)
    n := len(nums)
    last := nums[0]
    res := 0
    for i:=1 ; i<n ; i++ {
        if nums[i] <= last {
            res += last - nums[i] + 1
            last += 1
        } else {
            last = nums[i]
        }
    }
    return res
}
