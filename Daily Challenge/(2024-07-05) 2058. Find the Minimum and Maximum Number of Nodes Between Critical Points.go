/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func nodesBetweenCriticalPoints(head *ListNode) []int {
    var res []int
    count := 0
    prev := -1
    min_gap := 100009
    max_gap := 0
    first_point := -1
    latest_point := -1
    for head.Next != nil && head.Next.Next != nil {
        first := head.Val
        mid := head.Next.Val
        last := head.Next.Next.Val
        if (mid > first && mid > last) || (mid < first && mid < last) {
            latest_point = count
            if prev == -1 {
                prev = count
            } else {
                min_gap = min(min_gap, latest_point - prev)
            }
            if first_point == -1 {
                first_point = count
            }
            prev = latest_point
        }
        head = head.Next
        count++
    }
    res = append(res, -1)
    res = append(res, -1)
    if latest_point == -1 || min_gap == 100009{
        return res
    }
    res[0] = min_gap
    min_gap = min(min_gap, latest_point - first_point)
    max_gap = latest_point - first_point
    // fmt.Println(min_gap, max_gap, latest_point, first_point)
    res[1] = max_gap
    return res
}