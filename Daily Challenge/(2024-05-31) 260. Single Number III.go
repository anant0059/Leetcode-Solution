func singleNumber(nums []int) []int {
    // len := len(nums)
    xor := 0
    for _, num := range nums {
        xor ^= num
        // fmt.Println(num)
    }
    fmt.Println(xor)
    var res = []int{0, 0}
    count := 0
    first_bit_xor := xor
    for true {
        // fmt.Println(count)
        if first_bit_xor & 1  == 1 {
            break
        }
        first_bit_xor /= 2
        count++
    }
    first_bit_xor = int(math.Pow(2, float64(count)))
    fmt.Println(first_bit_xor)
    for _, num := range nums {
        if num & first_bit_xor == 0 {
            res[0] ^= num
        } else {
            res[1] ^= num
        }
    }
    return res
}