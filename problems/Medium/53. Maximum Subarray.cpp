class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res= INT_MIN, n=nums.size(),sm=0;
        for(int i=0;i<n;++i){
            if(nums[i]+sm<=0) res=max(res, nums[i]+sm),sm=0;
            else{
                sm+=nums[i];
                res=max(res, sm);
            }
        }
        return res;
    }
};