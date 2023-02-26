class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,mn=prices[0];
        for(auto i:prices){
            ans=max(ans,i-mn);
            mn=min(i,mn);
        }
        return ans;
    }
};