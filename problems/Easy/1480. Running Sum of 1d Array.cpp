class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size(),sm=0;
        vector<int> res(n,0);
        for(int i=0;i<n;++i){
            sm+=nums[i];
            res[i]=sm;
        }
        return res;
    }
};