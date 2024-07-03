func minDifference(nums []int) int {
    numsSize := len(nums)
	if numsSize <= 4 {
		return 0
	}

	// Partially sort the first four elements
	sort.Slice(nums[:4], func(i, j int) bool { return nums[i] < nums[j] })
	// Find the 4th largest element
	sort.Slice(nums[4:], func(i, j int) bool { return nums[4+i] < nums[4+j] })
	// Sort the last four elements
	sort.Slice(nums[numsSize-4:], func(i, j int) bool { return nums[numsSize-4+i] < nums[numsSize-4+j] })

	minDiff := math.MaxInt64

	// Four scenarios to compute the minimum difference
	for left, right := 0, numsSize-4; left < 4; left, right = left+1, right+1 {
		if diff := nums[right] - nums[left]; diff < minDiff {
			minDiff = diff
		}
	}

	return minDiff
}