class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int> mp;
        for(int i=0;i<n;++i){
            if(mp[target-nums[i]]){
                return {mp[target-nums[i]]-1,i};
            }
            mp[nums[i]]=i+1;
        }
        return {};
    }
};