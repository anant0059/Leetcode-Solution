func sortColors(nums []int)  {
    n := len(nums)
    zero := 0
    i := 0
    two := n - 1
    for i <= two {
        if nums[i] == 0 {
            tmp := nums[i]
            nums[i] = nums[zero]
            nums[zero] = tmp
            zero++
            i++
        } else if nums[i] == 1{
            i++
        } else {
            tmp := nums[i]
            nums[i] = nums[two]
            nums[two] = tmp
            two--
        }
    }
}