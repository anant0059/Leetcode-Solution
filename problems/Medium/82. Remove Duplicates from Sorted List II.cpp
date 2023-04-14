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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* res=NULL,* curr=NULL;
        while(head){
            int cnt=0;
            ListNode* temp=head;
            while(head && temp->val==head->val){
                head=head->next;
                cnt++;
            }
            if(cnt==1){
                if(res==NULL){
                    res=temp;
                    curr=temp;
                }
                else{
                    curr->next=temp;
                    curr=curr->next;
                }
                curr->next=NULL;
            }
        }
        return res;
    }
};