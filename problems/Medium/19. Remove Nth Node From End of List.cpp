/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         ListNode* prev=NULL,* curr=head;
        for(int i=0;i<n;++i){
            curr=curr->next;
        }
        while(curr){
            if(prev==NULL) prev=head;
            else prev=prev->next;
            curr=curr->next;
        }
        if(prev) {
            prev->next=prev->next->next;
            return head;
        }
        return head->next;
    }
};