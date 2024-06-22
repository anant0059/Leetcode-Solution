func numberOfSubarrays(nums []int, k int) int {
    subarrays := 0
    initialGap := 0
    qsize := 0
    start := 0

    for end := 0; end < len(nums); end++ {
        if nums[end]%2 == 1 {
            qsize++
        }

        if qsize == k {
            initialGap = 0
            for qsize == k {
                qsize -= nums[start] % 2
                initialGap++
                start++
            }
        }
        subarrays += initialGap
    }

    return subarrays
}