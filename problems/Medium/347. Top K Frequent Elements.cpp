class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto i:nums) mp[i]++;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto i:mp){
            if(pq.size()<k) pq.push({i.second,i.first});
            else if(pq.top().first<i.second) pq.pop(),pq.push({i.second,i.first});
        }
        vector<int> res;
        while(pq.size()) res.push_back(pq.top().second),pq.pop();
        return res;
    }
};