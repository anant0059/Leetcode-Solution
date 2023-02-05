class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<int,int> mp,mp1;
        vector<int> ans;
        int n=s.length(),m=p.length();
        if(n<m) return ans;
        for(int i=0;i<m;++i){
            mp[p[i]]++;
            mp1[s[i]]++;
        }
        for(int i=0;i<=n-m;++i){
            if(i!=0){
                mp1[s[i-1]]--;
                mp1[s[i+m-1]]++;
            }
            int temp=0;
            for(int j=0;j<26;++j){
                int x=int('a')+j;
                //cout<<x<<" ";
                if(mp1[x]==mp[x]) temp++;
            }
            cout<<temp<<" ";
            if(temp==26) ans.push_back(i);
        }
        return ans;    }
};