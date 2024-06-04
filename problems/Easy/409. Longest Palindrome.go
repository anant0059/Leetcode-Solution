func longestPalindrome(s string) int {
    freq := make(map[rune]int)
    for _, c := range s {
        freq[c]++
    }
    res := 0
    odd := 0
    for _, count := range freq {
        if count % 2 == 0 {
            res += count
        } else {
            odd = 1
            res += count - 1
        }
    }
    res += odd
    return res
}


    // n := len(s)
    // res := 0
    // for i:=0 ; i<n ; i++ {
    //     left := i - 1
    //     right := i + 1
    //     tmp := 1
    //     for left >= 0 && right < n {
    //         if s[left] == s[right] {
    //             tmp += 2
    //         } else {
    //             break
    //         }
    //         left--
    //         right++
    //     }
    //     res = max(res, tmp)
    //     left = i
    //     right = i + 1
    //     tmp = 0
    //     for left >= 0 && right < n {
    //         if s[left] == s[right] {
    //             tmp += 2
    //         } else {
    //             break
    //         }
    //         left--
    //         right++
    //     }
    //     res = max(res, tmp)
    // }
    // return res