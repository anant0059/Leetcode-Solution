class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto i:stones){
            pq.push(i);
        }
        while(pq.size()>1){
            int tmp1=pq.top();
            pq.pop();
            int tmp2=pq.top();
            pq.pop();
            if(abs(tmp2-tmp1)) pq.push(abs(tmp1-tmp2));
        }
        if(pq.size()) return pq.top();
        return 0;
    }
};