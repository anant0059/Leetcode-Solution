func minDifference(nums []int) int {
    numsSize := len(nums)
	if numsSize <= 4 {
		return 0
	}

	// Sort the array
	sort.Ints(nums)

	minDiff := math.MaxInt64

	// Four scenarios to compute the minimum difference
	for i := 0; i < 4; i++ {
		diff := nums[numsSize-4+i] - nums[i]
		if diff < minDiff {
			minDiff = diff
		}
	}

	return minDiff
}