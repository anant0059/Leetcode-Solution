class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size(),m=t.size(),i=0,j=0;
        if(n>m) return false;
        while(i<n && j<m ){
            int flag=0;
            while(j<m){
                if(s[i]==t[j]){
                    ++j;
                    flag=1;
                    break;
                }
                ++j;
            }
            if(flag==0) return false;
            ++i;
        }
        cout<<i<<endl;
        if(i!=n) return false;
        return true;
    }
};