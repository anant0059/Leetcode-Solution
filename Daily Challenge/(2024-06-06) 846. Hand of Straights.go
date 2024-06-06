func isNStraightHand(hand []int, groupSize int) bool {
    n := len(hand)
    slices.Sort(hand)
    if n % groupSize != 0 {
        return false
    }
    freq := make(map[int]int)
    for _, i := range hand {
        freq[i]++
    }
    // fmt.Println(freq)
    for _, card := range hand {
        if freq[card] == 0 {
            continue
        }
        tmp := groupSize
        for tmp > 0 {
            if freq[card + groupSize - tmp] > 0 {
                freq[card + groupSize - tmp]--
            } else {
                return false
            }
            tmp--
        }
        // card1 := card + 1
        // card2 := card + 2
        // card3 := card - 1
        // card4 := card - 2

        // if freq[card1] > 0 && freq[card2] > 0 {
        //     freq[card]--
        //     freq[card1]--
        //     freq[card2]--
        // } else if freq[card3] > 0 && freq[card4] > 0 {
        //     freq[card]--
        //     freq[card3]--
        //     freq[card4]--
        // } else {
        //     return false
        // }
    }
    return true
}