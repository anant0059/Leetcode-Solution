class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        map<int, int> mp;
        int res = 0;
        for(int i = 0; i < n; ++i) {
            if(mp[arr[i] - difference]) {
                mp[arr[i]] = max(mp[arr[i]], mp[arr[i] - difference] + 1);
            }
            mp[arr[i]] = max(1, mp[arr[i]]);
            res = max(res, mp[arr[i]]);
            // cout<< mp[arr[i]]<<" ";
        }
        return res;
    }
};