class Solution {
public:
    int appendCharacters(string t, string s) {
        int n=s.size(),m=t.size(),i=0,j=0;
        while(i<n && j<m){
            bool flag=0;
            while(j<m){
                if(s[i]==t[j]){
                    flag=1;
                    ++j;
                    break;
                }
                ++j;
            }
            if(flag==0) return n-i;
            ++i;
        }
        //cout<<"nf";
        return n-i;
    }
};