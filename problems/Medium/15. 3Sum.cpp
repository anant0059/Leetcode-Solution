class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> res;
        for(int i=0;i<n;){
            int left=i+1,right=n-1;
            while(left<right){
                int sm=nums[i]+nums[left]+nums[right];
                if(sm<0) left++;
                else if(sm>0) right--;
                else{
                    res.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(left<n && left<=right && nums[left-1]==nums[left]) left++;
                    while(right>0 && left>=right && nums[right+1]==nums[right]) right--;
                }
            }
            i++;
            while(i<n && nums[i]==nums[i-1]) i++;
        }
        return res;
    }
};