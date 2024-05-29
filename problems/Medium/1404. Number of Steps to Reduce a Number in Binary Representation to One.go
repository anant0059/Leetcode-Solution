func numSteps(s string) int {
    n := len(s)
    res := 0
    carry_forward := 0
    for i := n-1 ; i > 0 ; i-- {
        if s[i] == '1' {
            if carry_forward == 0 {
                res += 2
            } else {
                res += 1
            }
            carry_forward = 1
        } else {
            if carry_forward == 0 {
                res += 1
            } else {
                res += 2
                carry_forward = 1 // already this value so required to update just for understanding
            }
        }
    }
    if carry_forward == 1 {
        res += 1
    }
    return res
}