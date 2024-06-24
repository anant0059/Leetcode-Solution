func minKBitFlips(nums []int, k int) int {
    // Tracks the current number of flips
    currentFlips := 0
    // Tracks the total number of flips
    totalFlips := 0

    for i := 0; i < len(nums); i++ {
        // If the window slides out of the range and the leftmost element
        // is marked as flipped (2), decrement currentFlips
        if i >= k && nums[i-k] == 2 {
            currentFlips--
        }

        // Check if the current bit needs to be flipped
        if currentFlips%2 == nums[i] {
            // If flipping would exceed array bounds, return -1
            if i+k > len(nums) {
                return -1
            }
            // Mark the current bit as flipped
            nums[i] = 2
            currentFlips++
            totalFlips++
        }
    }

    return totalFlips
}