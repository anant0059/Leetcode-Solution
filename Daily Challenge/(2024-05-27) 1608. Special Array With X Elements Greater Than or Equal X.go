func specialArray(nums []int) int {
    n := len(nums)
    freq := make([]int, n+1)
    
    for i:=0 ; i<n ; i++ {
        freq[min(n, nums[i])]++
    }

    greater_equal_num := 0
    for i:=n ; i>=1 ; i-- {
        greater_equal_num += freq[i]
        if greater_equal_num == i {
            return i
        }
    }

    return -1
}