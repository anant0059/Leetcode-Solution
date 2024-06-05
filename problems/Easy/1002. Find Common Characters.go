func commonChars(words []string) []string {
    n := len(words)
    var res []string
    common_char := make([]int, 26)
    for _, c := range words[0] {
        common_char[int(c - 'a')] ++ ;
    }

    for i:=1; i<n ; i++ {
        current_char := make([]int, 26)
        for _, c := range words[i] {
            current_char[int(c - 'a')] ++ ;
        }
        for j:=0 ; j<26 ; j++ {
            common_char[j] = min(common_char[j], current_char[j])
        }
    }
    // fmt.Println(common_char)

    for i:=0; i<26; i++ {
        for count:=0; count<common_char[i]; count++ {
            tmp := 'a' + i
            // fmt.Println(tmp, count, common_char[i], i)
            res = append(res, string(tmp))
        }
    }
    return res
}