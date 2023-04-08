class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0 ) return "";
        int n=strs.size(),n0=strs[0].size();
        for(int i=0;i<n0;++i){
            for(int j=0;j<n ;++j){
                if( strs[j].size()==i || strs[0][i]!=strs[j][i]){   //return ;
                    string ans="";
                    for(int k=0;k<i;++k){
                        ans+=strs[0][k];
                    }
                    return ans;
                }
            }
        }
        return strs[0];
    }
};