class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<vector<long long>> v;
        for(int i = 0; i < n; ++i) {
            v.push_back({(long long)nums[i], (long long)cost[i]});
        }
        sort(v.begin(), v.end());
        vector<long long> forward(n, 0), backward(n, 0);
        long long cost_ = v[0][1];
        for(int i = 1; i < n; ++i) {
            forward[i] = forward[i-1] + cost_ * (v[i][0] - v[i-1][0]);
            cost_ += v[i][1];
        }
        cost_ = v[n-1][1];
        for(int i = n - 2; i >= 0; --i) {
            backward[i] = backward[i+1] + cost_ * (v[i+1][0] - v[i][0]);
            cost_ += v[i][1];
        }
        long long res = forward[0] + backward[0];
        for(int i = 0; i < n; ++i) {
            if(res > forward[i] + backward[i]) {
                res = forward[i] + backward[i];
            }
            // cout<< res<<endl;
            // cout<<forward[i] + backward[i]<< " "<< forward[i] << " " << backward[i]<<endl;
        }
        return res;
    }
};

// 1 2 3 5
// 2 14 3 1