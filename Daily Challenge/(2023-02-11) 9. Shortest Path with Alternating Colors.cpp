class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> v(n);
        for(auto i: redEdges){
            v[i[0]].push_back({i[1],0});
        }
        for(auto i: blueEdges){
            v[i[0]].push_back({i[1],1});
        }

        vector<int> res(n,-1);
        vector<vector<int>> vis(n, vector<int>(2,0));
        vis[0][0]=1,
        vis[0][1]=1;
        res[0]=0;

        queue<vector<int>> q;
        q.push({0,0});
        q.push({0,1});
        int dis=0;
        while(q.size()){
            int len=q.size();
            while(len--){
                int prev_node=q.front()[0],color=q.front()[1];
                q.pop();
                for(auto i:v[prev_node]){
                    if(color!=i.second && vis[i.first][i.second]==0){
                        q.push({i.first, i.second});
                        vis[i.first][i.second]=1;
                    }
                }
                if(res[prev_node]!=-1) res[prev_node]=min(dis,res[prev_node]);
                else res[prev_node]=dis;
            }
            dis++;
        }
        return res;
    }
};