func f(nums []int, index int, currXOR int) int {
    // fmt.Println(len(nums), index)
    if index == len(nums) {
        return currXOR
    }

    withNum := f(nums, index + 1, currXOR ^ nums[index])
    withoutNum := f(nums, index + 1, currXOR)

    return withNum + withoutNum
}

func subsetXORSum(nums []int) int {
    return f(nums, 0, 0)
}