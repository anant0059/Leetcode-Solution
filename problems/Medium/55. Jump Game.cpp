class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(),mx=0;
        if(n<=1) return 1;
        for(int i=0;i<n-1;++i){
            mx=max(mx,i+nums[i]);
            if(mx==i) return 0;
        }
        return mx>=n-1;
    }
};