func reverseString(s []byte)  {
    // fmt.Println(s)
    n := len(s)
    i, j := 0, n-1
    for i < j {
        tmp := s[i]
        s[i] = s[j]
        s[j] = tmp
        i++
        j--
    }
}