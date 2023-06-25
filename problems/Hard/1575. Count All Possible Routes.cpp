class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {                
        const int MOD = 1000000007;
        int n = locations.size();    
        
        vector<vector<int>> dp(n, vector<int>(fuel + 1, 0));
        for (int f = 0; f <= fuel; f++) {
            dp[finish][f] = 1;
        }
        
        // for each fuel, we calculate all cross between cities
        for (int f = 0; f <= fuel; f++) {
            for (int city = 0; city < n; city++) {            
                for (int nextCity = 0; nextCity < n; nextCity++) {               
                    if (nextCity != city && f >= abs(locations[nextCity] - locations[city])) {
                        dp[city][f] = (dp[city][f] + dp[nextCity][f - abs(locations[nextCity] - locations[city])]) % MOD;
                    }
                }
            }            
        }
        return dp[start][fuel];
    }
};