class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size(), ans=n+1, first=0,last=0, sm=0;
        for(int i=0;i<n;++i){
            sm+=nums[i];
            last++;
            while(sm>=target){
                sm-=nums[first];
                first++;
                ans=min(ans,last-first+1);
            }
        }
        if(ans==n+1) return 0;
        return ans;
    }
};