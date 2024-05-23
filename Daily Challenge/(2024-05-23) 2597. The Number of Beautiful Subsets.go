func beautifulSubsets(nums []int, k int) int {
	totalCount := 1
	freqMap := make(map[int]map[int]int)

	// Calculate frequencies based on remainder
	for _, num := range nums {
		remainder := num % k
		if _, exists := freqMap[remainder]; !exists {
			freqMap[remainder] = make(map[int]int)
		}
		freqMap[remainder][num]++
	}

	// Iterate through each remainder group
	for _, fr := range freqMap {
		keys := make([]int, 0, len(fr))
		for key := range fr {
			keys = append(keys, key)
		}
		sort.Ints(keys)

		prevNum := -k
		prev2, prev1 := 1, 1

		// Iterate through each number in the current remainder group
		for _, num := range keys {
			freq := fr[num]

			// Count of subsets skipping the current number
			skip := prev1

			// Count of subsets including the current number
			var take int
			if num-prevNum == k {
				take = powerSet(freq) * prev2
			} else {
				take = powerSet(freq) * prev1
			}

			// Store the total count for the current number
			curr := skip + take
			prev2 = prev1
			prev1 = curr
			prevNum = num
		}
		totalCount *= prev1
	}
	return totalCount - 1
}

// Helper function to generate power set excluding the empty set
func powerSet(freq int) int {
	return (1 << freq) - 1
}