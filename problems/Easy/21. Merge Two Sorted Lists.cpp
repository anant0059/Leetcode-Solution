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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* res=NULL;
        ListNode* prev=NULL;
        ListNode* curr=NULL;
        while(list1 && list2){
            if(list1->val > list2->val){
                curr=list2;
                list2=list2->next;
            }
            else{
                curr=list1;
                list1=list1->next;
            }
            if(res==NULL){
                prev=curr;
                res=curr;
            }
            else{
                prev->next=curr;
                prev=curr;
            }
        }
        if(!list1){
            prev->next=list2;
        }
        else{
            prev->next=list1;
        }
        return res;
    }
};