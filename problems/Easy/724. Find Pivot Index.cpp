class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sm=0,lsm=0,n=nums.size();
        for(auto i:nums) sm+=i;
        for(int i=0;i<n;++i){
            if(sm-lsm-nums[i]==lsm) return i;
            lsm+=nums[i];
        }
        return -1;
    }
};