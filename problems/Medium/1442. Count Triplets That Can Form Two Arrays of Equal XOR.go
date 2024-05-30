func countTriplets(arr []int) int {
    count_freq := make(map[int]int)
    total_sub_count := make(map[int]int)
    count_freq[0] = 1
    n := len(arr)
    res := 0
    prefix := 0
    for i:=0 ; i<n; i++ {
        prefix ^= arr[i]
        res += (count_freq[prefix] * i) - total_sub_count[prefix]
        count_freq[prefix]++
        total_sub_count[prefix] += i+1
    }
    return res
}