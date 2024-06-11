func relativeSortArray(arr1 []int, arr2 []int) []int {
    mx := 0
    for _, e := range arr1 {
        mx = max(mx, e)
    }
    arr := make([]int, mx+1)
    for _, e := range arr1 {
        arr[e]++
    } 
    var res []int
    for _, e := range arr2 {
        for arr[e] > 0 {
            res = append(res, e)
            arr[e]--
        }
    }
    for i:=0 ; i<=mx ; i++ {
        for arr[i] > 0 {
            res = append(res, i)
            arr[i]--
        }
    }
    return res
}