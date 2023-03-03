class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> mp;
        int ans=INT_MAX, b=0, a=0, l=0, o=0, n=0;
        for(auto i:text){
            mp[i]++;
        }
        for(auto i: mp){
            if(i.first=='b'){
                ans=min(ans, i.second);
                b=1;
            }
            else if(i.first=='a'){
                ans=min(ans, i.second);
                a=1;
            }
            else if(i.first=='n'){
                ans=min(ans, i.second);
                n=1;
            }
            else if(i.first=='l'){
                ans=min(ans, i.second/2);
                l=1;
            }
            else if(i.first=='o'){
                ans=min(ans, i.second/2);
                o=1;
            }
        }
        if(b && a && l && o && n) return ans;
        return 0;
    }
};