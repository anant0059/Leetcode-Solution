func splitArray(nums []int, k int) int {
    n := len(nums)
    low := 0
    high := 0
    for i:=0; i<n; i++ {
        high += nums[i]
        if low < nums[i] {
            low = nums[i]
        }
    }
    ans := 0
    for low <= high {
        mid := (low+high)/2
        count := 1
        tmpsm := 0
        for i:=0; i<n; i++ {
            if tmpsm+nums[i]<=mid {
                tmpsm+=nums[i];
            } else{
                count += 1
                tmpsm = nums[i]
            }
        }

        if count <= k{
            high = mid -1
            ans = mid
        } else {
            low = mid + 1
        }
    }
    return ans
}