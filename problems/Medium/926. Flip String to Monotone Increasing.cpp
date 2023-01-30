class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size(),zero=0,one=0,ans=0;
        for(auto i:s){
            if(i=='0') zero++;
        }
        one=n-zero;
        int tillzero=0,tillone=0;
        ans=min(n,min(one,zero));
        for(auto i:s){
            if(i=='0') tillzero++;
            else tillone++;
            ans=min(ans,tillone+zero-tillzero);
        }
        return ans;
    }
};