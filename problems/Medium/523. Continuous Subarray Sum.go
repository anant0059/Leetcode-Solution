func checkSubarraySum(nums []int, k int) bool {
    index := make(map[int]int)
    sm := 0
    for i, num := range nums {
        sm += num%k
        sm %= k
        if sm == 0 && i != 0 {
            return true
        }
        if index[sm] == 0 {
            index[sm] = i + 1
            continue
        }
        if i + 1 - index[sm] > 1 {
            return true
        }
        if index[sm] > 0 {
            continue
        }
        index[sm] = i + 1
    }
    return false
}