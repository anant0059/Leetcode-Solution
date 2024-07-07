func numWaterBottles(numBottles int, numExchange int) int {
    res := numBottles
    remaining := numBottles
    for remaining >= numExchange {
        tmp := remaining
        remaining = remaining / numExchange
        res += remaining
        // fmt.Println(remaining)
        remaining += tmp % numExchange
        // fmt.Println(remaining)
    }
    // res == remaining
    return res
}