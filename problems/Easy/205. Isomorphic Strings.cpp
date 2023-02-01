class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        map<char,char> mp1,mp2;
        for(int i=0;i<n;++i){
            if((mp1[s[i]] || mp2[t[i]]) && (t[i]!=mp1[s[i]] || s[i]!=mp2[t[i]])){
                cout<<i<<endl;
                return false;
            }
            mp1[s[i]]=t[i];
            mp2[t[i]]=s[i];
        }
        return true;
    }
};