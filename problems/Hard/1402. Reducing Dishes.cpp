class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size(),mx=0;
        sort(satisfaction.begin(),satisfaction.end());
        for(int i=0;i<n;++i){
            int sm=0;
            for(int j=i;j<n;++j){
                sm+=satisfaction[j]*(j-i+1);
            }
            mx=max(mx,sm);
        }
        return mx;
    }
};