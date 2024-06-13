func minMovesToSeat(seats []int, students []int) int {
    n := len(seats)
    slices.Sort(seats)
    slices.Sort(students)
    res := 0
    for i:=0 ; i<n ; i++ {
        res += int(math.Abs(float64(seats[i]) - float64(students[i])))
    }
    return res
}