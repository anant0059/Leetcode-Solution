func subsets(nums []int) [][]int {
    len := float64(len(nums))
    n := int(math.Pow(2, len))
    var res [][]int
    for i:=0 ; i<n ; i++ {
        var tmp []int
        ind := 0
        val := i
        for val > 0 {
            if val & 1 > 0 {
                tmp = append(tmp, nums[ind])
            }
            val = val/2
            ind = ind + 1
        }
        res = append(res, tmp)
    }
    return res
}