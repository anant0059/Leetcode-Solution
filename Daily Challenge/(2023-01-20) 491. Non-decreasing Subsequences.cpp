class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n=nums.size(),i=0;
        set<vector<int>> res,q;
        q.insert({nums[i]});
        ++i;
        while(i<n){
            //cout<<q.size()<<endl;
            set<vector<int>> tt=q;
            for(auto vec:tt){
                vector<int> temp=vec;
                //cout<<vec.size()<<endl;
                if(temp[temp.size()-1]<=nums[i]){
                    vector<int> temp1=temp;
                    temp1.push_back(nums[i]);
                    if(temp1.size()>1) res.insert(temp1);
                    q.insert(temp1);
                }
                q.insert({nums[i]});
            }
            i++;
        }
        return vector(res.begin(),res.end());
    }
};