func isPossibleDivide(nums []int, k int) bool {
    n := len(nums)
    slices.Sort(nums)
    
    if n % k != 0 {
        return false
    }

    freq := make(map[int]int)
    for _, i := range nums {
        freq[i]++
    }
    
    for _, card := range nums {
        if freq[card] == 0 {
            continue
        }
        tmp := k
        for tmp > 0 {
            if freq[card + k - tmp] > 0 {
                freq[card + k - tmp]--
            } else {
                return false
            }
            tmp--
        }
    }
    return true
}