func wordBreak(s string, wordDict []string) []string {
    n := len(s)
    freq := make(map[string]int)
    for _,i := range wordDict {
        freq[i] = 1
    }
    // fmt.Println(freq)
    var queue [][]string
    queue = append(queue, []string{string(s[0])})
    // fmt.Println(queue)
    var res []string

    for i:=1 ; i<n ; i++ {
        queue_len := len(queue)
        for queue_len > 0 {
            tmp := queue[0]
            // fmt.Println("tmp", tmp)
            queue = queue[1:]
            // fmt.Println(queue)
            tmp_len := len(tmp)
            if freq[tmp[tmp_len-1]] > 0 {
                tmp1 := make([]string, len(tmp))
				copy(tmp1, tmp)
                tmp1 = append(tmp1, string(s[i]))
                queue = append(queue, tmp1)
            }
            tmp[tmp_len-1] += string(s[i])
            queue = append(queue, tmp)
            queue_len--
        }
    }
    for _, stringArray := range queue {
		tmpLen := len(stringArray)
		if tmpLen > 0 {
			if _, exists := freq[stringArray[tmpLen-1]]; exists {
				var tmp string
				for i, c := range stringArray {
					tmp = tmp + c
					if i != tmpLen-1 {
						tmp += " "
					}
				}
				res = append(res, tmp)
			}
		}
	}
    return res
}