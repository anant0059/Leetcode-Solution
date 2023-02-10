class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==1) q.push({i,j});
            }
        }
        int count=0;
        while(q.size()){
            int len=q.size();
            while(len--){
                int x=q.front().first;
                int y=q.front().second;
                
                q.pop();
                if(x+1<=grid.size()-1 && grid[x+1][y]==0){
                    q.push({x+1,y});
                    grid[x+1][y]=1;
                }
                if(x-1>=0 &&grid[x-1][y]==0){
                    q.push({x-1,y});
                    grid[x-1][y]=1;
                }
                if(y+1<=grid[0].size()-1 && grid[x][y+1]==0){
                     q.push({x,y+1});
                     grid[x][y+1]=1;
                }                   
                if(y-1>=0 &&grid[x][y-1]==0){
                    q.push({x,y-1});
                    grid[x][y-1]=1;
                }
            }
            ++count;
        }
        if(count>1) return count-1;
        return -1;
    }
};