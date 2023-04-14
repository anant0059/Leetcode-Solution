class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        vector < vector < int > > dp( 1000, vector < int > ( 1000, 0 ) );
        return find( s, 0, s.size() - 1, dp );
    }

    int find( string &s, int l, int r, vector < vector < int > > &dp )
    {
        if( l > r )
        {
            return 0;
        }
        if( l == r )
        {
            return 1;
        }
        if( dp[l][r] != 0 )
        {
            return dp[l][r];
        }
        if( s[l] == s[r] )
        {
            return dp[l][r] = find( s, l + 1, r - 1, dp ) + 2;
        }
        return dp[l][r] = max( find( s, l + 1, r, dp ), find( s, l, r - 1, dp ) );
    }
};