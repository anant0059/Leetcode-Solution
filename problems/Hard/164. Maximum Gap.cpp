class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res=0, n=nums.size();
        for(int i=1;i<n;++i){
            res=max(res, nums[i]-nums[i-1]);
        }
        
        return res;
    }
};