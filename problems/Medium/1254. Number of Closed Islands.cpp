class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = 0;
        vector< vector < int > > move = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
        for( int i = 0; i < m; ++i ){
            if( grid[0][i] == 0 )
            {
                queue< pair< int, int> > q;
                q.push( { 0, i } );
                while( q.size() )
                {
                    int ro = q.front().first, col = q.front().second;
                    q.pop();
                    for( auto ii: move )
                    {
                        if( ro + ii[0] < n && ro + ii[0] >= 0 && col + ii[1] < m && col + ii[1] >=0 && grid[ro + ii[0]][col + ii[1]] == 0 )
                        {
                            q.push( { ro + ii[0], col + ii[1] } );
                        }
                    }
                    grid[ro][col] = 1;
                }
            }
            if( grid[n-1][i] == 0 )
            {
                queue< pair< int, int> > q;
                q.push( { n-1, i } );
                while( q.size() )
                {
                    int ro = q.front().first, col = q.front().second;
                    q.pop();
                    for( auto ii: move )
                    {
                        if( ro + ii[0] < n && ro + ii[0] >= 0 && col + ii[1] < m && col + ii[1] >=0 && grid[ro + ii[0]][col + ii[1]] == 0 )
                        {
                            q.push( { ro + ii[0], col + ii[1] } );
                        }
                    }
                    grid[ro][col] = 1;
                }
            }
        }

        for( int i = 0; i < n; ++i ){
            if( grid[i][0] == 0 )
            {
                queue< pair< int, int> > q;
                q.push( { i, 0 } );
                while( q.size() )
                {
                    int ro = q.front().first, col = q.front().second;
                    q.pop();
                    for( auto ii: move )
                    {
                        if( ro + ii[0] < n && ro + ii[0] >= 0 && col + ii[1] < m && col + ii[1] >=0 && grid[ro + ii[0]][col + ii[1]] == 0 )
                        {
                            q.push( { ro + ii[0], col + ii[1] } );
                        }
                    }
                    grid[ro][col] = 1;
                }
            }
            if( grid[i][m-1] == 0 )
            {
                queue< pair< int, int> > q;
                q.push( { i, m-1 } );
                while( q.size() )
                {
                    int ro = q.front().first, col = q.front().second;
                    q.pop();
                    for( auto ii: move )
                    {
                        if( ro + ii[0] < n && ro + ii[0] >= 0 && col + ii[1] < m && col + ii[1] >=0 && grid[ro + ii[0]][col + ii[1]] == 0 )
                        {
                            q.push( { ro + ii[0], col + ii[1] } );
                        }
                    }
                    grid[ro][col] = 1;
                }
            }
        }

        for( int i = 0; i < n; ++i )
        {
            for( int j = 0; j < m; ++j )
            {
                if( grid[i][j] == 0 )
                {
                    queue< pair< int, int> > q;
                    q.push( { i, j } );
                    while( q.size() )
                    {
                        int ro = q.front().first, col = q.front().second;
                        q.pop();
                        for( auto ii: move )
                        {
                            if( ro + ii[0] < n && ro + ii[0] >= 0 && col + ii[1] < m && col + ii[1] >=0 && grid[ro + ii[0]][col + ii[1]] == 0 )
                            {
                                q.push( { ro + ii[0], col + ii[1] } );
                            }
                        }
                        grid[ro][col] = 1;
                    }
                    ++res;
                }
                // cout<< grid[i][j]<<" ";
            }
            // cout<< endl;
        }
        return res;
    }
};