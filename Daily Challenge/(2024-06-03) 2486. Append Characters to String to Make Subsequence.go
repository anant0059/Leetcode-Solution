func appendCharacters(s string, t string) int {
    len_s, len_t, i, j := len(s), len(t), 0, 0
    for i < len_s && j < len_t {
        if s[i] == t[j] {
            j++
        }
        i++
    }
    return (len_t - j)
}