class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int first=0, second=0, n=cost.size();
        for(int i=2;i<=n;++i){
            int tmp=min(first+cost[i-2],second+cost[i-1]);
            first=second;
            second=tmp;
        }
        return second;
    }
};