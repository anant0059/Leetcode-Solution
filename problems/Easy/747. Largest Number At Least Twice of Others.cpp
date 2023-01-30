class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int mx1=0,mx2=0,ind=0,n=nums.size();
        for(int i=0;i<n;++i){
            if(mx1<=nums[i]){
                mx2=mx1;
                mx1=nums[i];
                ind=i;
            }
            else if(mx2<nums[i]) mx2=nums[i];
        }
        if(mx2*2<=mx1) return ind;
        return -1;
    }
};