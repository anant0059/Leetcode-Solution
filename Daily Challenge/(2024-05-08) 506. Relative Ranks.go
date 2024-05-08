func findRelativeRanks(score []int) []string {
    type athlete struct {
        score int
        index int
    }
    len := len(score)
    
    var athletes []athlete
    for i:=0;i<len;i++ {
        athletes = append(athletes, athlete{score[i], i})
    }

    sort.Slice(athletes, func(i, j int) bool{
        return athletes[i].score > athletes[j].score
    })
    result := make([]string, len)
    for i, athlete := range athletes {
        switch i {
            case 0:
                result[athlete.index] = "Gold Medal"
            case 1:
                result[athlete.index] = "Silver Medal"
            case 2:
                result[athlete.index] = "Bronze Medal"
            default:
                result[athlete.index] = strconv.Itoa(i+1)
        }
    }
    return result
}