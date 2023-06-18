class Solution {
public:
    long long find(vector<vector<int>> &grid, vector<vector<long long>> &paths, int i, int j, int &n, int &m) {
        if( i < 0 || j < 0 || i >=n || j >= m) {
            return 0;
        }
        if(paths[i][j] > 0) {
            return paths[i][j];
        }
        long long tmp = 0;
        if(i - 1 >= 0 && grid[i-1][j] > grid[i][j]) {
            tmp += find(grid, paths, i - 1, j, n, m) % (1000000007);
        }
        if(i + 1 < n && grid[i+1][j] > grid[i][j]) {
            tmp += find(grid, paths, i + 1, j, n, m) % (1000000007);
        }
        if(j - 1 >= 0 && grid[i][j-1] > grid[i][j]) {
            tmp += find(grid, paths, i, j - 1, n, m) % (1000000007);
        }
        if(j + 1 < m && grid[i][j+1] > grid[i][j]) {
            tmp += find(grid, paths, i, j + 1, n, m) % (1000000007);
        }
        tmp += 1;
        paths[i][j] = tmp % 1000000007;
        return paths[i][j];
    }

    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        long long res = 0;
        vector<vector<long long>> paths(n, vector<long long> (m, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                find(grid, paths, i, j, n, m);
                res += (paths[i][j]) % (1000000007);
            }
        }
        return (int)(res % 1000000007);
    }
};