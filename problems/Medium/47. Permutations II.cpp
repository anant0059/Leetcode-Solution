class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        res.push_back(nums);
        sort(nums.begin(),nums.end());
        
        map<vector<int>,int> mp;
        
        for(int i=0;i<n;++i){
            int sz=res.size();
            for(int t=0;t<sz;++t){
                vector<int> temp=res[t];
                for(int j=i+1;j<n;++j){
                    if(temp[i]==temp[j]) continue;
                    vector<int> temp2=temp;
                    swap(temp2[i],temp2[j]);
                    if(!mp[temp2]) res.push_back(temp2),mp[temp2]++;
                }
            }
        }
        return res;
    }
};