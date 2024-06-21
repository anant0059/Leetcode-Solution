import (
    "sort"
)

func maxDistance(position []int, m int) int {
    n := len(position)
    sort.Ints(position) // sorting the positions array
    low := 1
    high := position[n-1] - position[0]
    res := 0
    
    for low <= high {
        mid := (low + high) / 2
        if canPlaceBalls(position, m, mid) {
            res = mid // update the result with mid
            low = mid + 1 // try for a larger minimum distance
        } else {
            high = mid - 1 // try for a smaller minimum distance
        }
    }
    return res
}

func canPlaceBalls(position []int, m int, minDist int) bool {
    count := 1 // place the first ball
    lastPos := position[0]
    
    for i := 1; i < len(position); i++ {
        if position[i] - lastPos >= minDist {
            count++ // place another ball
            lastPos = position[i]
            if count == m {
                return true
            }
        }
    }
    return false
}
