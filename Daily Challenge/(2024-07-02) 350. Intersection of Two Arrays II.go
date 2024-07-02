func intersect(nums1 []int, nums2 []int) []int {
    mp := make(map[int]int)
    // fmt.Println(mp)
    var res []int
    for _, num := range nums1 {
        mp[num]++
    }
    // fmt.Println(mp)
    for _, num := range nums2 {
        if mp[num] > 0 {
            res = append(res, num)
            mp[num]--
        }
    }
    return res
}