class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> v(26,0);
        int n=s.size(), i=0, j=0, ans=0;
        while(i<n && j<n){
            int tmp=0;
            v[s[j]-'A']++;
            for(auto x:v){
                tmp=max(tmp, x);
            }
            if(j-i+1-tmp>k){
                v[s[i]-'A']--;
                ++i;
            }
            ans=max(ans, j-i+1);
            ++j;
        }
        return ans;
    }
};