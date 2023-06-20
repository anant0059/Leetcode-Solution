class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long n = nums.size(), sm = 0;
        vector<int> res(n, -1);
        for(int i = 0; i < 2*k && i < n; ++i) {
            sm += nums[i];
        }
        for(int i = k; i < n - k; ++i) {
            sm += nums[i+k];
            res[i] = sm/(2 * k + 1);
            sm -= nums[i-k];
        }
        return res;
    }
};