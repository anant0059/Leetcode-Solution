class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid){
        queue<vector<int>> q;
        int n=grid.size();;
        if(n==0 || grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        q.push({0,0,1});
        vector<vector<int>> visited(n,vector<int> (n,0));
        vector<vector<int>> dir={{-1,0},{-1,-1},{-1,1},{0,-1},{0,1},{1,0},{1,1},{1,-1}};
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int x=q.front()[0],y=q.front()[1],dis=q.front()[2];
                q.pop();
                if(visited[x][y]) continue;
                if(x==n-1 && y==n-1) return dis;
                for(auto i:dir){
                    if(x+i[0]<n && x+i[0]>=0 && y+i[1]<n && y+i[1]>=0 && grid[x+i[0]][y+i[1]]==0 && visited[x+i[0]][y+i[1]]==0)  q.push({x+i[0],y+i[1],dis+1});
                }
                visited[x][y]=1;
            }
        }
        return -1;
    }
};