class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=pow(2,nums.size());
        vector<vector<int>> ans;
        for(int i=0;i<n;++i){
            vector<int>temp;
            int x=i,c=0;
            while(x){
                if(x&1) temp.push_back(nums[c]);
                c++;
                x/=2;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};