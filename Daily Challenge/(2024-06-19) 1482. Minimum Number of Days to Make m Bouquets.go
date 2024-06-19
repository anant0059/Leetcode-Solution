func minDays(bloomDay []int, m int, k int) int {
    n := len(bloomDay)
    if m * k > n {
        return -1
    }
    
    low := bloomDay[0]
    high := bloomDay[0]
    for i:=0; i<n; i++ {
        low = min(low, bloomDay[i])
        high = max(high, bloomDay[i])
    }
    ans := 0
    for low <= high {
        mid := int((low+high)/2)
        count := 0
        i := 0
        for i <= n - k {
            tmp_count := 0
            // fmt.Println(i)
            for j := i; j < i + k; j++ {
                // fmt.Println(i, j)
                if bloomDay[j] <= mid {
                    tmp_count++
                } else {
                    break
                }
            }
            i += tmp_count
            if tmp_count == k {
                count++
            } else {
                i++
            }
        }
        // fmt.Println("here", low, high, count)
        if count < m {
            low = mid + 1
        } else {
            high = mid -1
            ans = mid
        }
    }
    return ans
}