import "math"
import "fmt"

func maxScoreWords(words []string, letters []byte, score []int) int {
    n := len(words)
    res := 0
    freq := make(map[int]int)
    for _, c := range letters {
        tmp := int(c) - int('a')
        freq[tmp]++
    }
    // fmt.Println(freq)

    for i := 1; i < int(math.Pow(2,float64(n))); i++ {
        // fmt.Println(i)
        tmp := i
        index := 0
        tmp_res := 0
        flag := 1
        tmp_freq := make(map[int]int)
        for tmp > 0 {
            if tmp % 2 == 1 {
                for _, c := range words[index] {
                    c_value := int(c) - int('a')
                    tmp_freq[c_value]++
                    if tmp_freq[c_value] > freq[c_value] {
                        flag = 0
                        break
                    }
                    tmp_res += score[c_value]
                }
            }
            if flag == 0 {
                break
            }
            // fmt.Println(tmp, index, tmp_res)
            index++
            tmp = tmp/2
        }
        if flag == 1 {
            res = max(res, tmp_res)
        }
        // fmt.Println(" ")
    }
    return res
}