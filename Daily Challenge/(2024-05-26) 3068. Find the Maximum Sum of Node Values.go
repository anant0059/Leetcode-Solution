func maximumValueSum(nums []int, k int, edges [][]int) int64 {
    len := len(nums)
    netChange := make([]int,len)
    nodeSum := 0
    for i:=0 ; i<len ; i++ {
        nodeSum += nums[i]
        netChange[i] = (nums[i]^k) - nums[i]
    }

    sort.Sort(sort.Reverse(sort.IntSlice(netChange)))

    for i:=0 ; i<len ; i+=2{
        if i+1 == len {
            break
        }
        tmp := netChange[i] + netChange[i+1]
        if tmp > 0 {
            nodeSum += tmp
        }
    }
    return netChange
}