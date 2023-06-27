class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> res;
        map<int, map<int,int>> mp;
        priority_queue <pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({nums1[0] + nums2[0], {0, 0}});
        mp[0][0] = 1;
        while(k-- && pq.size()) {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            res.push_back({nums1[x], nums2[y]});
            if(x + 1 < n && mp[x+1][y] == 0) {
                pq.push({nums1[x+1] + nums2[y], {x + 1, y}});
                mp[x+1][y] = 1;
            }
            if(y + 1 < m && mp[x][y+1] == 0) {
                pq.push({nums1[x] + nums2[y+1], {x, y + 1}});
                mp[x][y+1] = 1;
            }
        }
        return res;
    }
};