class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        dp[n-1]=0;
        for(int i=n-2;i>=0;--i){
            //cout<<i<<"fidsok"<<endl;
            int tmp=n,j=1;
            //cout<<i<<" "<<j<<" "<<"ij"<<endl;
            while(j<=nums[i] && i+j<n){
                tmp=min(tmp, dp[i+j]+1);
                //cout<<dp[i+j]<<" "<<i<<" "<<j<<"dkf"<<endl;
                ++j;
            }
            dp[i]=tmp;
            //cout<<dp[i]<<" "<<i<<endl;
        }
        return dp[0];
    }
};