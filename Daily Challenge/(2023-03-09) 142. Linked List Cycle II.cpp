/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*,int> mp;
        while(head){
            if(mp[head]) return head;
            mp[head]++;
            head=head->next;
        }
        return NULL;
    }
};