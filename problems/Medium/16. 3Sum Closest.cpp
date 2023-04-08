class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=0,mn=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>1;--i){
            int j=0,k=i-1;
            while(j<k){
                int sm=nums[i]+nums[j]+nums[k];
                if(abs(target-sm)<mn){
                    mn=abs(target-sm);
                    ans=sm;
                }
                if(sm>target) k--;
                else if(sm<target) j++;
                else return ans;
            }
        }
        return ans;
    }
};