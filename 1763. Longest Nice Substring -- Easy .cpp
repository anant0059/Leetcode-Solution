class Solution {
public:
    string longestNiceSubstring(string s) {
        int n=s.size(),diff='a'-'A';
        for(int i=0;i<n;++i){
            int f=0,l=n-i-1;
            while(l<n){
                //cout<<f<<" "<<l<<endl;
                map<char,int> mp;
                bool flag=1;
                for(int j=f;j<=l;++j) mp[s[j]]++;
                for(char c='a';c<='z';++c){
                    if((mp[c] && mp[c-diff]==0) or (mp[c]==0 && mp[c-diff])) flag=0l;
                }
                //cout<<flag<<endl;
                if(flag) return s.substr(f,l-f+1);
                f++,l++;
            }
        }
        return "";
    }
};