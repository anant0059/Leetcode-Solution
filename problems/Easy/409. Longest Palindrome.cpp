class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;
        for(auto i:s) mp[i]++;
        int ans=0,odd=0;
        for(auto i:mp){
            //cout<<i<<endl;
            if(i.second%2){
                odd=1;
                ans+=i.second-1;
            }
            else{
                ans+=i.second;
            }
        }
        if(odd) ans++;
        return ans;
    }
};