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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* first=head;
        ListNode* last=head;
        int n=1;
        while(first!=NULL && first->next!=NULL){
            first=first->next;
            n++;
        }
        first=head;
        k=k%n;
        if(n==0 ) return NULL;
        if(n==1 || k==0)  return head;
        //cout<<k<<" "<<n;
        
        
        while(k--){
            last=last->next;
        }
        while(last->next!=NULL){
            first=first->next;
            last=last->next;
        }
        //return first;
        ListNode* x=head;
        head=first->next;
        first->next=NULL;
        last->next=x;
        return head;
    }
};