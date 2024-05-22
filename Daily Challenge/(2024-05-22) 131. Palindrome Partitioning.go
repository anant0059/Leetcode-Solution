func partition(s string) [][]string {
    var res [][]string
    // fmt.Println(res)
    // x := "iofd"
    // x = x + string('d')
    // fmt.Println(x)
    var queue [][]string
    queue = append(queue, []string{string(s[0])})
    n := len(s)
    for i:=1; i<n ; i++ {
        tmp_len := len(queue)
        for tmp_len > 0 {
            tmp := queue[0]
            queue = queue[1:len(queue)]
            if isPalindrome(tmp[len(tmp)-1]) {
                tmp1 := make([]string, len(tmp))
                copy(tmp1, tmp)
                tmp1 = append(tmp1, string(s[i]))
                queue = append(queue, tmp1)
            }
            tmp[len(tmp)-1] = tmp[len(tmp)-1] + string(s[i])
            queue = append(queue, tmp)
            tmp_len--;
        }
    }
    for len(queue) > 0 {
        if isPalindrome(queue[0][len(queue[0])-1]) {
            res = append(res, queue[0])
        }
        queue = queue[1:len(queue)]
    }
    return res
}

func isPalindrome(s string) bool {
    for i,j:=0,len(s)-1; i<j; i,j=i+1,j-1 {
        if s[i]!=s[j] {
            return false
        }
    }

    return true
}