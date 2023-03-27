class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp( n, vector<int> (m, 0) );
        for( int i = 0; i < n; ++i )
        {
            for( int j = 0; j < m; ++j )
            {
                if( i == 0 && j == 0)
                {
                    dp[i][j] = grid[0][0];
                }
                else if( i == 0 )
                {
                    dp[i][j] = dp[0][j-1] + grid[0][j];
                }
                else if ( j == 0 )
                {
                    dp[i][j] = dp[i-1][0] + grid[i][0];
                }
                else
                {
                    dp[i][j] = grid[i][j] + min( dp[i][j-1], dp[i-1][j] );
                }
            }
        }
        return dp[n-1][m-1];
    }
};