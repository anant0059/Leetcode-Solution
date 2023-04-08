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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for(auto i: lists){
            if(i) pq.push({i->val, i});
        }
        ListNode* res=new ListNode();
        ListNode* curr=res;
        while(pq.size()){
            ListNode* tmp=pq.top().second;
            pq.pop();
            if(tmp->next) pq.push({tmp->next->val, tmp->next});
            curr->next=tmp;
            curr=curr->next;
        }
        return res->next;
    }
};