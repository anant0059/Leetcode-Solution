class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int tar=target-(nums[i]+nums[j]);
                int l=j+1,r=n-1;
                while(l<r){
                    int sum=nums[l]+nums[r];
                    if(sum>tar) r--;
                    else if(sum<tar) l++;
                    else{       //(sum==tar)
                        vector<int> v={nums[i],nums[j],nums[l],nums[r]};
                        res.push_back(v);
                        while(l<r and v[2]==nums[l]) l++;
                        while(l<r and v[3]==nums[r]) r--;
                    }
                }
                while(j<n-1 and nums[j]==nums[j+1]) j++;
            }
            while(i<n-1 and nums[i]==nums[i+1]) i++;
        }
        
        return res;
        
    }
};