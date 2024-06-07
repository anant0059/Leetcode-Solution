func replaceWords(dictionary []string, sentence string) string {
    n := len(sentence)
    freq := make(map[string]int)
    for _, i := range dictionary {
        freq[i]++
    }
    temp := ""
    res := ""
    for i:=0 ; i<n ; i++ {
        if sentence[i] == ' ' {
            res += temp + " "
            temp = ""
        } else {
            temp += string(sentence[i])
            if freq[temp] > 0 {
                res += temp
                for i < n && sentence[i] != ' ' {
                    i++
                }
                if i < n && sentence[i] == ' ' {
                    res += " "
                }
                temp = ""
            }
        }
    }
    res += temp
    return res
}