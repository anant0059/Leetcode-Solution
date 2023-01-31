class Solution {
public:
    // bool comp(vector<int> first, vector<int> second){
    //     if(first[0]==second[0]){
    //         return first[1]<second[1];
    //     }
    //     return first[0]<second[0];
    // }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=scores.size();
        vector<vector<int>> ages_scores;
        for(int i=0;i<n;++i){
            ages_scores.push_back({ages[i],scores[i]});
        }
        sort(ages_scores.begin(),ages_scores.end());
        // for(auto i:ages_scores){
        //     cout<<i[0]<<" "<<i[1]<<endl;
        // }
        // return 0;
        vector<int> dp(n,0);
        int res=0;
        for(int i=n-1;i>=0;--i){
            int mx=ages_scores[i][1];
            for(int j=i+1;j<n;++j){
                if(ages_scores[i][1]<=ages_scores[j][1]){
                    mx=max(mx,ages_scores[i][1]+dp[j]);
                }
            }
            dp[i]=mx;
            res=max(res,mx);
        }
        return res;
    }
};