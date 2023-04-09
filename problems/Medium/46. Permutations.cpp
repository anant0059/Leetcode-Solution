class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        queue<vector<int>> q;
        q.push(nums);
        res.push_back(nums);
        
        vector<int> temp=q.front(),temp2;
        for(int i=0;i<n;++i){
            int sz=q.size();
            while(sz--){
                temp=q.front(),temp2;
                for(int j=i+1;j<n;++j){
                    temp2=temp;
                    swap(temp2[i],temp2[j]);
                    q.push(temp2);
                    res.push_back(temp2);
                }
                q.push(temp);
                q.pop();
            }
        }
        return res;
    }
};