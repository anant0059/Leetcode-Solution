/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func mergeNodes(head *ListNode) *ListNode {
    dummy := &ListNode{}
    cur := dummy
    head = head.Next
    sum := 0
    for head != nil {
        if head.Val == 0 {
            cur.Next = head
            head.Val = sum
            cur = cur.Next
            sum = 0
        } else {
           sum += head.Val 
        }
        head = head.Next
    }
    return dummy.Next
}