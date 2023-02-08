class Solution {
public:
    void Island(vector<vector<char>>& grid ,int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0') return;
        grid[i][j]='0';
        Island(grid, i+1, j);
        Island(grid, i-1, j);
        Island(grid, i, j+1);
        Island(grid,  i, j-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size(), ans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]=='1'){
                    ans++;
                    Island(grid,i,j);
                }
            }
        }
        return ans;
    }
};