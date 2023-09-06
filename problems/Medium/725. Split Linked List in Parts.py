# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        l = 0
        curr = head
        while curr:
            l += 1
            curr = curr.next
        
        linked_list_len = l//k
        remaining = l - k*linked_list_len
        count = 0
        k_temp = 0
        res = []
        while head:
            k_temp += 1
            temp = head
            l_temp = 0
            prev = head
            while l_temp < linked_list_len:
                prev = head
                head = head.next
                l_temp += 1
            if count < remaining:
                prev = head
                head = head.next
                count += 1
            prev.next = None
            res.append(temp)
        while k_temp < k:
            res.append(None)
            k_temp += 1
        return res